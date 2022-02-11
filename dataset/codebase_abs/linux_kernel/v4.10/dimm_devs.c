int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( ! V_3 -> V_4 ||
! F_3 ( V_5 , & V_3 -> V_4 ) ) {
if ( V_3 -> V_6 & V_7 )
return - V_8 ;
else
return - V_9 ;
}
return 0 ;
}
static int F_4 ( struct V_10 * V_11 )
{
int V_12 ;
if ( ! V_11 )
return - V_13 ;
V_12 = F_1 ( V_11 -> V_2 ) ;
if ( V_12 )
F_5 ( V_11 -> V_2 , L_1 ,
F_6 ( 0 ) , V_14 , V_12 ) ;
return V_12 ;
}
int F_7 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = & V_11 -> V_17 ;
struct V_18 * V_18 = F_8 ( V_11 -> V_2 ) ;
struct V_19 * V_20 ;
int V_12 = F_4 ( V_11 ) ;
if ( V_12 )
return V_12 ;
if ( V_16 -> V_21 )
return 0 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_20 = V_18 -> V_20 ;
return V_20 -> V_22 ( V_20 , F_2 ( V_11 -> V_2 ) ,
V_23 , V_16 , sizeof( * V_16 ) , NULL ) ;
}
int F_9 ( struct V_10 * V_11 )
{
struct V_18 * V_18 = F_8 ( V_11 -> V_2 ) ;
struct V_24 * V_16 ;
struct V_19 * V_20 ;
int V_12 = F_4 ( V_11 ) ;
T_1 V_25 , V_21 ;
T_2 V_26 ;
if ( V_12 )
return V_12 ;
if ( V_11 -> V_27 )
return 0 ;
if ( V_11 -> V_17 . V_28 || V_11 -> V_17 . V_29 == 0
|| V_11 -> V_17 . V_21 < V_30 ) {
F_5 ( V_11 -> V_2 , L_2 ,
V_11 -> V_17 . V_29 , V_11 -> V_17 . V_21 ) ;
return - V_8 ;
}
V_11 -> V_27 = F_10 ( V_11 -> V_17 . V_21 , V_31 ) ;
if ( ! V_11 -> V_27 )
V_11 -> V_27 = F_11 ( V_11 -> V_17 . V_21 ) ;
if ( ! V_11 -> V_27 )
return - V_32 ;
V_25 = F_12 ( T_1 , V_33 , V_11 -> V_17 . V_29 ) ;
V_16 = F_13 ( V_25 + sizeof( * V_16 ) , V_31 ) ;
if ( ! V_16 )
return - V_32 ;
V_20 = V_18 -> V_20 ;
for ( V_21 = V_11 -> V_17 . V_21 , V_26 = 0 ;
V_21 ; V_21 -= V_16 -> V_34 ,
V_26 += V_16 -> V_34 ) {
V_16 -> V_34 = F_14 ( V_21 , V_25 ) ;
V_16 -> V_35 = V_26 ;
V_12 = V_20 -> V_22 ( V_20 , F_2 ( V_11 -> V_2 ) ,
V_5 , V_16 ,
V_16 -> V_34 + sizeof( * V_16 ) , NULL ) ;
if ( V_12 || V_16 -> V_28 ) {
V_12 = - V_8 ;
break;
}
memcpy ( V_11 -> V_27 + V_26 , V_16 -> V_36 , V_16 -> V_34 ) ;
}
F_5 ( V_11 -> V_2 , L_3 , V_14 , V_26 , V_12 ) ;
F_15 ( V_16 ) ;
return V_12 ;
}
int F_16 ( struct V_10 * V_11 , T_2 V_26 ,
void * V_37 , T_2 V_38 )
{
int V_12 = F_4 ( V_11 ) ;
T_2 V_25 , V_39 ;
struct V_40 * V_16 ;
struct V_18 * V_18 = F_8 ( V_11 -> V_2 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
if ( V_12 )
return V_12 ;
if ( ! V_11 -> V_27 )
return - V_8 ;
if ( V_26 + V_38 > V_11 -> V_17 . V_21 )
return - V_8 ;
V_25 = F_12 ( T_1 , V_33 , V_38 ) ;
V_25 = F_12 ( T_1 , V_25 , V_11 -> V_17 . V_29 ) ;
V_16 = F_13 ( V_25 + sizeof( * V_16 ) + sizeof( T_1 ) , V_31 ) ;
if ( ! V_16 )
return - V_32 ;
for ( V_39 = 0 ; V_38 ; V_38 -= V_16 -> V_34 ,
V_39 += V_16 -> V_34 ) {
T_2 V_41 ;
T_1 * V_28 ;
V_16 -> V_35 = V_26 + V_39 ;
V_16 -> V_34 = F_14 ( V_25 , V_38 ) ;
memcpy ( V_16 -> V_42 , V_37 + V_39 , V_16 -> V_34 ) ;
V_41 = sizeof( * V_16 ) + V_16 -> V_34 + sizeof( T_1 ) ;
V_28 = ( ( void * ) V_16 ) + V_41 - sizeof( T_1 ) ;
V_12 = V_20 -> V_22 ( V_20 , F_2 ( V_11 -> V_2 ) ,
V_43 , V_16 , V_41 , NULL ) ;
if ( V_12 || * V_28 ) {
V_12 = V_12 ? V_12 : - V_8 ;
break;
}
}
F_15 ( V_16 ) ;
return V_12 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_6 |= V_7 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_19 ( & V_44 , V_3 -> V_45 ) ;
F_15 ( V_3 ) ;
}
bool F_20 ( struct V_1 * V_2 )
{
return V_2 -> type == & V_46 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_21 ( V_2 , struct V_3 , V_2 ) ;
F_22 ( ! F_20 ( V_2 ) ) ;
return V_3 ;
}
struct V_3 * F_23 ( struct V_47 * V_48 )
{
struct V_49 * V_49 = & V_48 -> V_49 ;
struct V_50 * V_50 = & V_49 -> V_51 [ 0 ] ;
return V_50 -> V_3 ;
}
struct V_10 * F_24 ( struct V_50 * V_50 )
{
struct V_3 * V_3 = V_50 -> V_3 ;
F_25 ( ! F_26 ( & V_3 -> V_2 ) ) ;
return F_27 ( & V_3 -> V_2 ) ;
}
void F_28 ( struct V_52 * V_52 )
{
struct V_10 * V_11 = F_21 ( V_52 , F_29 ( * V_11 ) , V_52 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_53 * V_54 , * V_55 ;
F_5 ( V_2 , L_4 , V_14 ) ;
F_30 ( V_2 ) ;
F_31 (ndd, res, _r)
F_32 ( V_11 , V_54 ) ;
F_33 ( V_2 ) ;
F_34 ( V_11 -> V_27 ) ;
F_15 ( V_11 ) ;
F_35 ( V_2 ) ;
}
void F_36 ( struct V_10 * V_11 )
{
F_37 ( & V_11 -> V_52 ) ;
}
void F_38 ( struct V_10 * V_11 )
{
if ( V_11 )
F_39 ( & V_11 -> V_52 , F_28 ) ;
}
const char * F_40 ( struct V_3 * V_3 )
{
return F_41 ( & V_3 -> V_2 ) ;
}
struct V_56 * F_42 ( struct V_3 * V_3 )
{
return & V_3 -> V_2 . V_57 ;
}
unsigned long F_43 ( struct V_3 * V_3 )
{
return V_3 -> V_4 ;
}
void * F_44 ( struct V_3 * V_3 )
{
if ( V_3 )
return V_3 -> V_58 ;
return NULL ;
}
static T_3 F_45 ( struct V_1 * V_2 ,
struct V_59 * V_60 , char * V_37 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_16 , V_38 = 0 ;
if ( ! V_3 -> V_4 )
return sprintf ( V_37 , L_5 ) ;
F_46 (cmd, &nvdimm->cmd_mask, BITS_PER_LONG)
V_38 += sprintf ( V_37 + V_38 , L_6 , F_47 ( V_16 ) ) ;
V_38 += sprintf ( V_37 + V_38 , L_5 ) ;
return V_38 ;
}
static T_3 F_48 ( struct V_1 * V_2 , struct V_59 * V_60 ,
char * V_37 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_30 ( V_2 ) ;
F_33 ( V_2 ) ;
return sprintf ( V_37 , L_4 , F_49 ( & V_3 -> V_61 )
? L_7 : L_8 ) ;
}
static T_3 F_50 ( struct V_1 * V_2 ,
struct V_59 * V_60 , char * V_37 )
{
struct V_10 * V_11 = F_27 ( V_2 ) ;
T_3 V_12 ;
T_1 V_62 ;
if ( ! V_11 )
return - V_8 ;
F_30 ( V_2 ) ;
V_62 = F_51 ( V_11 ) ;
if ( V_62 - 1 > V_62 ) {
F_52 ( V_2 , 1 , L_9 ) ;
V_62 = 0 ;
} else
V_62 -- ;
V_12 = sprintf ( V_37 , L_10 , V_62 ) ;
F_33 ( V_2 ) ;
return V_12 ;
}
struct V_3 * F_53 ( struct V_18 * V_18 , void * V_58 ,
const struct V_63 * * V_64 , unsigned long V_6 ,
unsigned long V_4 , int V_65 ,
struct V_53 * V_66 )
{
struct V_3 * V_3 = F_13 ( sizeof( * V_3 ) , V_31 ) ;
struct V_1 * V_2 ;
if ( ! V_3 )
return NULL ;
V_3 -> V_45 = F_54 ( & V_44 , 0 , 0 , V_31 ) ;
if ( V_3 -> V_45 < 0 ) {
F_15 ( V_3 ) ;
return NULL ;
}
V_3 -> V_58 = V_58 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_65 = V_65 ;
V_3 -> V_66 = V_66 ;
F_55 ( & V_3 -> V_61 , 0 ) ;
V_2 = & V_3 -> V_2 ;
F_56 ( V_2 , L_11 , V_3 -> V_45 ) ;
V_2 -> V_67 = & V_18 -> V_2 ;
V_2 -> type = & V_46 ;
V_2 -> V_68 = F_57 ( V_69 , V_3 -> V_45 ) ;
V_2 -> V_64 = V_64 ;
F_58 ( V_2 ) ;
return V_3 ;
}
int F_59 ( struct V_1 * V_2 , void * V_27 )
{
T_4 V_70 , V_71 , V_72 , V_61 ;
struct V_73 * V_74 = V_27 ;
struct V_50 * V_50 ;
struct V_49 * V_49 ;
struct V_10 * V_11 ;
struct V_53 * V_54 ;
int V_75 ;
if ( ! F_60 ( V_2 ) )
return 0 ;
V_49 = F_61 ( V_2 ) ;
for ( V_75 = 0 ; V_75 < V_49 -> V_76 ; V_75 ++ ) {
V_50 = & V_49 -> V_51 [ V_75 ] ;
if ( V_50 -> V_3 == V_74 -> V_50 -> V_3 )
break;
}
if ( V_75 >= V_49 -> V_76 )
return 0 ;
V_11 = F_24 ( V_50 ) ;
V_70 = V_50 -> V_77 + V_50 -> V_78 - 1 ;
V_71 = V_50 -> V_77 ;
if ( V_74 -> V_54 ) {
if ( V_74 -> V_54 -> V_77 >= V_50 -> V_77
&& V_74 -> V_54 -> V_77 < V_70 )
;
else
return 0 ;
}
V_79:
V_61 = 0 ;
F_62 (ndd, res) {
if ( ( V_54 -> V_77 >= V_71 && V_54 -> V_77 < V_70 )
|| ( V_54 -> V_80 >= V_71
&& V_54 -> V_80 <= V_70 ) ) {
if ( strncmp ( V_54 -> V_81 , L_12 , 4 ) == 0 ) {
V_72 = F_63 ( V_71 , F_14 ( V_70 + 1 ,
V_54 -> V_80 + 1 ) ) ;
if ( V_72 != V_71 ) {
V_71 = V_72 ;
goto V_79;
}
} else
V_61 += F_14 ( V_70 , V_54 -> V_80 )
- F_63 ( V_50 -> V_77 , V_54 -> V_77 ) + 1 ;
} else if ( V_50 -> V_77 > V_54 -> V_77
&& V_70 < V_54 -> V_80 ) {
V_61 += V_50 -> V_78 ;
break;
}
}
if ( V_74 -> V_54 && V_71 > V_74 -> V_54 -> V_77 ) {
V_74 -> V_54 -> V_77 = F_63 ( V_74 -> V_54 -> V_77 , V_71 ) ;
if ( V_74 -> V_54 -> V_77 > V_74 -> V_54 -> V_80 )
V_74 -> V_54 -> V_80 = V_74 -> V_54 -> V_77 - 1 ;
return 1 ;
}
V_74 -> V_82 -= V_71 - V_50 -> V_77 + V_61 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , void * V_27 )
{
struct V_73 * V_74 = V_27 ;
struct V_50 * V_50 ;
struct V_49 * V_49 ;
T_4 V_70 ;
int V_75 ;
if ( ! F_60 ( V_2 ) )
return 0 ;
V_49 = F_61 ( V_2 ) ;
for ( V_75 = 0 ; V_75 < V_49 -> V_76 ; V_75 ++ ) {
V_50 = & V_49 -> V_51 [ V_75 ] ;
if ( V_50 -> V_3 == V_74 -> V_50 -> V_3 )
break;
}
if ( V_75 >= V_49 -> V_76 )
return 0 ;
V_70 = V_50 -> V_77 + V_50 -> V_78 - 1 ;
if ( V_74 -> V_54 -> V_77 >= V_50 -> V_77
&& V_74 -> V_54 -> V_77 < V_70 ) {
if ( V_74 -> V_54 -> V_80 <= V_70 ) {
V_74 -> V_61 = 0 ;
return 1 ;
} else {
V_74 -> V_61 -= V_74 -> V_54 -> V_80 - V_70 ;
return 0 ;
}
} else if ( V_74 -> V_54 -> V_80 >= V_50 -> V_77
&& V_74 -> V_54 -> V_80 <= V_70 ) {
V_74 -> V_61 -= V_50 -> V_77 - V_74 -> V_54 -> V_77 ;
return 0 ;
} else {
V_74 -> V_61 -= V_50 -> V_78 ;
return 0 ;
}
}
T_4 F_65 ( struct V_49 * V_49 )
{
struct V_18 * V_18 = F_8 ( & V_49 -> V_2 ) ;
struct V_50 * V_50 = & V_49 -> V_51 [ 0 ] ;
struct V_10 * V_11 = F_24 ( V_50 ) ;
struct V_73 V_74 = {
. V_50 = V_50 ,
. V_82 = V_50 -> V_78 ,
. V_54 = NULL ,
} ;
struct V_53 * V_54 ;
if ( ! V_11 )
return 0 ;
F_66 ( & V_18 -> V_2 , & V_74 , F_59 ) ;
F_62 (ndd, res) {
if ( strncmp ( V_54 -> V_81 , L_13 , 3 ) != 0 )
continue;
V_74 . V_54 = V_54 ;
V_74 . V_61 = F_67 ( V_54 ) ;
F_66 ( & V_18 -> V_2 , & V_74 , F_64 ) ;
V_74 . V_82 -= V_74 . V_61 ;
}
return V_74 . V_82 ;
}
T_4 F_68 ( struct V_49 * V_49 ,
struct V_50 * V_50 , T_4 * V_83 )
{
T_4 V_84 , V_70 , V_61 = 0 , V_82 , V_71 ;
struct V_10 * V_11 = F_24 ( V_50 ) ;
struct V_53 * V_54 ;
const char * V_85 ;
if ( ! V_11 )
return 0 ;
V_84 = V_50 -> V_77 ;
V_70 = V_84 + V_50 -> V_78 - 1 ;
V_71 = F_63 ( V_84 , V_70 + 1 - * V_83 ) ;
F_62 (ndd, res) {
if ( V_54 -> V_77 >= V_84 && V_54 -> V_77 < V_70 ) {
if ( strncmp ( V_54 -> V_81 , L_13 , 3 ) == 0 )
V_71 = F_14 ( V_71 ,
F_63 ( V_84 , V_54 -> V_77 ) ) ;
else if ( V_54 -> V_80 > V_70 ) {
V_85 = L_14 ;
goto V_86;
} else
V_61 += F_67 ( V_54 ) ;
} else if ( V_54 -> V_80 >= V_84 && V_54 -> V_80 <= V_70 ) {
if ( strncmp ( V_54 -> V_81 , L_13 , 3 ) == 0 ) {
V_71 = V_84 ;
} else
V_61 += F_67 ( V_54 ) ;
} else if ( V_84 > V_54 -> V_77 && V_84 < V_54 -> V_80 ) {
V_61 += V_50 -> V_78 ;
V_71 = V_84 ;
}
}
* V_83 = V_70 + 1 - V_71 ;
V_82 = V_71 - V_84 ;
if ( V_61 < V_82 )
return V_82 - V_61 ;
return 0 ;
V_86:
F_69 ( V_49 , V_11 , V_54 , L_4 , V_85 ) ;
return 0 ;
}
void F_32 ( struct V_10 * V_11 , struct V_53 * V_54 )
{
F_25 ( ! F_26 ( V_11 -> V_2 ) ) ;
F_15 ( V_54 -> V_81 ) ;
F_70 ( & V_11 -> V_87 , V_54 -> V_77 , F_67 ( V_54 ) ) ;
}
struct V_53 * F_71 ( struct V_10 * V_11 ,
struct V_88 * V_89 , T_4 V_77 ,
T_4 V_90 )
{
char * V_81 = F_72 ( V_89 , sizeof( * V_89 ) , V_31 ) ;
struct V_53 * V_54 ;
if ( ! V_81 )
return NULL ;
F_25 ( ! F_26 ( V_11 -> V_2 ) ) ;
V_54 = F_73 ( & V_11 -> V_87 , V_77 , V_90 , V_81 , 0 ) ;
if ( ! V_54 )
F_15 ( V_81 ) ;
return V_54 ;
}
T_4 F_74 ( struct V_10 * V_11 ,
struct V_88 * V_89 )
{
T_4 V_91 = 0 ;
struct V_53 * V_54 ;
F_62 (ndd, res)
if ( strcmp ( V_54 -> V_81 , V_89 -> V_45 ) == 0 )
V_91 += F_67 ( V_54 ) ;
return V_91 ;
}
static int F_75 ( struct V_1 * V_2 , void * V_92 )
{
int * V_93 = V_92 ;
if ( F_20 ( V_2 ) )
( * V_93 ) ++ ;
return 0 ;
}
int F_76 ( struct V_18 * V_18 , int V_94 )
{
int V_93 = 0 ;
F_77 () ;
F_66 ( & V_18 -> V_2 , & V_93 , F_75 ) ;
F_5 ( & V_18 -> V_2 , L_15 , V_14 , V_93 ) ;
if ( V_93 != V_94 )
return - V_8 ;
return 0 ;
}
void T_5 F_78 ( void )
{
F_79 ( & V_44 ) ;
}
