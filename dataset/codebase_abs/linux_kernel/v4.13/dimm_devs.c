int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( ! V_3 -> V_4 ||
! F_3 ( V_5 , & V_3 -> V_4 ) ) {
if ( F_3 ( V_6 , & V_3 -> V_7 ) )
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
int V_21 = 0 ;
if ( V_12 )
return V_12 ;
if ( V_16 -> V_22 )
return 0 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_20 = V_18 -> V_20 ;
V_12 = V_20 -> V_23 ( V_20 , F_2 ( V_11 -> V_2 ) ,
V_24 , V_16 , sizeof( * V_16 ) , & V_21 ) ;
if ( V_12 < 0 )
return V_12 ;
return V_21 ;
}
int F_9 ( struct V_10 * V_11 )
{
struct V_18 * V_18 = F_8 ( V_11 -> V_2 ) ;
struct V_25 * V_16 ;
struct V_19 * V_20 ;
int V_12 = F_4 ( V_11 ) ;
T_1 V_26 , V_22 ;
T_2 V_27 ;
if ( V_12 )
return V_12 ;
if ( V_11 -> V_28 )
return 0 ;
if ( V_11 -> V_17 . V_29 || V_11 -> V_17 . V_30 == 0
|| V_11 -> V_17 . V_22 < V_31 ) {
F_5 ( V_11 -> V_2 , L_2 ,
V_11 -> V_17 . V_30 , V_11 -> V_17 . V_22 ) ;
return - V_8 ;
}
V_11 -> V_28 = F_10 ( V_11 -> V_17 . V_22 , V_32 ) ;
if ( ! V_11 -> V_28 )
return - V_33 ;
V_26 = F_11 ( T_1 , V_34 , V_11 -> V_17 . V_30 ) ;
V_16 = F_12 ( V_26 + sizeof( * V_16 ) , V_32 ) ;
if ( ! V_16 )
return - V_33 ;
V_20 = V_18 -> V_20 ;
for ( V_22 = V_11 -> V_17 . V_22 , V_27 = 0 ;
V_22 ; V_22 -= V_16 -> V_35 ,
V_27 += V_16 -> V_35 ) {
V_16 -> V_35 = F_13 ( V_22 , V_26 ) ;
V_16 -> V_36 = V_27 ;
V_12 = V_20 -> V_23 ( V_20 , F_2 ( V_11 -> V_2 ) ,
V_5 , V_16 ,
V_16 -> V_35 + sizeof( * V_16 ) , NULL ) ;
if ( V_12 || V_16 -> V_29 ) {
V_12 = - V_8 ;
break;
}
memcpy ( V_11 -> V_28 + V_27 , V_16 -> V_37 , V_16 -> V_35 ) ;
}
F_5 ( V_11 -> V_2 , L_3 , V_14 , V_27 , V_12 ) ;
F_14 ( V_16 ) ;
return V_12 ;
}
int F_15 ( struct V_10 * V_11 , T_2 V_27 ,
void * V_38 , T_2 V_39 )
{
int V_12 = F_4 ( V_11 ) ;
T_2 V_26 , V_40 ;
struct V_41 * V_16 ;
struct V_18 * V_18 = F_8 ( V_11 -> V_2 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
if ( V_12 )
return V_12 ;
if ( ! V_11 -> V_28 )
return - V_8 ;
if ( V_27 + V_39 > V_11 -> V_17 . V_22 )
return - V_8 ;
V_26 = F_11 ( T_1 , V_34 , V_39 ) ;
V_26 = F_11 ( T_1 , V_26 , V_11 -> V_17 . V_30 ) ;
V_16 = F_12 ( V_26 + sizeof( * V_16 ) + sizeof( T_1 ) , V_32 ) ;
if ( ! V_16 )
return - V_33 ;
for ( V_40 = 0 ; V_39 ; V_39 -= V_16 -> V_35 ,
V_40 += V_16 -> V_35 ) {
T_2 V_42 ;
T_1 * V_29 ;
V_16 -> V_36 = V_27 + V_40 ;
V_16 -> V_35 = F_13 ( V_26 , V_39 ) ;
memcpy ( V_16 -> V_43 , V_38 + V_40 , V_16 -> V_35 ) ;
V_42 = sizeof( * V_16 ) + V_16 -> V_35 + sizeof( T_1 ) ;
V_29 = ( ( void * ) V_16 ) + V_42 - sizeof( T_1 ) ;
V_12 = V_20 -> V_23 ( V_20 , F_2 ( V_11 -> V_2 ) ,
V_44 , V_16 , V_42 , NULL ) ;
if ( V_12 || * V_29 ) {
V_12 = V_12 ? V_12 : - V_8 ;
break;
}
}
F_14 ( V_16 ) ;
return V_12 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_17 ( V_6 , & V_3 -> V_7 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_17 ( V_45 , & V_3 -> V_7 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_20 ( & V_46 , V_3 -> V_47 ) ;
F_14 ( V_3 ) ;
}
bool F_21 ( struct V_1 * V_2 )
{
return V_2 -> type == & V_48 ;
}
struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_22 ( V_2 , struct V_3 , V_2 ) ;
F_23 ( ! F_21 ( V_2 ) ) ;
return V_3 ;
}
struct V_3 * F_24 ( struct V_49 * V_50 )
{
struct V_51 * V_51 = & V_50 -> V_51 ;
struct V_52 * V_52 = & V_51 -> V_53 [ 0 ] ;
return V_52 -> V_3 ;
}
unsigned long F_25 ( struct V_49 * V_50 )
{
return V_54 ;
}
struct V_10 * F_26 ( struct V_52 * V_52 )
{
struct V_3 * V_3 = V_52 -> V_3 ;
F_27 ( ! F_28 ( & V_3 -> V_2 ) ) ;
return F_29 ( & V_3 -> V_2 ) ;
}
void F_30 ( struct V_55 * V_55 )
{
struct V_10 * V_11 = F_22 ( V_55 , F_31 ( * V_11 ) , V_55 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_56 * V_57 , * V_58 ;
F_5 ( V_2 , L_4 , V_14 ) ;
F_32 ( V_2 ) ;
F_33 (ndd, res, _r)
F_34 ( V_11 , V_57 ) ;
F_35 ( V_2 ) ;
F_36 ( V_11 -> V_28 ) ;
F_14 ( V_11 ) ;
F_37 ( V_2 ) ;
}
void F_38 ( struct V_10 * V_11 )
{
F_39 ( & V_11 -> V_55 ) ;
}
void F_40 ( struct V_10 * V_11 )
{
if ( V_11 )
F_41 ( & V_11 -> V_55 , F_30 ) ;
}
const char * F_42 ( struct V_3 * V_3 )
{
return F_43 ( & V_3 -> V_2 ) ;
}
struct V_59 * F_44 ( struct V_3 * V_3 )
{
return & V_3 -> V_2 . V_60 ;
}
unsigned long F_45 ( struct V_3 * V_3 )
{
return V_3 -> V_4 ;
}
void * F_46 ( struct V_3 * V_3 )
{
if ( V_3 )
return V_3 -> V_61 ;
return NULL ;
}
static T_3 F_47 ( struct V_1 * V_2 ,
struct V_62 * V_63 , char * V_38 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_16 , V_39 = 0 ;
if ( ! V_3 -> V_4 )
return sprintf ( V_38 , L_5 ) ;
F_48 (cmd, &nvdimm->cmd_mask, BITS_PER_LONG)
V_39 += sprintf ( V_38 + V_39 , L_6 , F_49 ( V_16 ) ) ;
V_39 += sprintf ( V_38 + V_39 , L_5 ) ;
return V_39 ;
}
static T_3 F_50 ( struct V_1 * V_2 , struct V_62 * V_63 ,
char * V_38 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_32 ( V_2 ) ;
F_35 ( V_2 ) ;
return sprintf ( V_38 , L_4 , F_51 ( & V_3 -> V_64 )
? L_7 : L_8 ) ;
}
static T_3 F_52 ( struct V_1 * V_2 ,
struct V_62 * V_63 , char * V_38 )
{
struct V_10 * V_11 = F_29 ( V_2 ) ;
T_3 V_12 ;
T_1 V_65 ;
if ( ! V_11 )
return - V_8 ;
F_32 ( V_2 ) ;
V_65 = F_53 ( V_11 ) ;
if ( V_65 - 1 > V_65 ) {
F_54 ( V_2 , 1 , L_9 ) ;
V_65 = 0 ;
} else
V_65 -- ;
V_12 = sprintf ( V_38 , L_10 , V_65 ) ;
F_35 ( V_2 ) ;
return V_12 ;
}
struct V_3 * F_55 ( struct V_18 * V_18 , void * V_61 ,
const struct V_66 * * V_67 , unsigned long V_7 ,
unsigned long V_4 , int V_68 ,
struct V_56 * V_69 )
{
struct V_3 * V_3 = F_12 ( sizeof( * V_3 ) , V_32 ) ;
struct V_1 * V_2 ;
if ( ! V_3 )
return NULL ;
V_3 -> V_47 = F_56 ( & V_46 , 0 , 0 , V_32 ) ;
if ( V_3 -> V_47 < 0 ) {
F_14 ( V_3 ) ;
return NULL ;
}
V_3 -> V_61 = V_61 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_68 = V_68 ;
V_3 -> V_69 = V_69 ;
F_57 ( & V_3 -> V_64 , 0 ) ;
V_2 = & V_3 -> V_2 ;
F_58 ( V_2 , L_11 , V_3 -> V_47 ) ;
V_2 -> V_70 = & V_18 -> V_2 ;
V_2 -> type = & V_48 ;
V_2 -> V_71 = F_59 ( V_72 , V_3 -> V_47 ) ;
V_2 -> V_67 = V_67 ;
F_60 ( V_2 ) ;
return V_3 ;
}
int F_61 ( struct V_1 * V_2 , void * V_28 )
{
T_4 V_73 , V_74 , V_75 ;
struct V_76 * V_77 = V_28 ;
struct V_52 * V_52 ;
struct V_51 * V_51 ;
struct V_10 * V_11 ;
struct V_56 * V_57 ;
int V_78 ;
if ( ! F_62 ( V_2 ) )
return 0 ;
V_51 = F_63 ( V_2 ) ;
for ( V_78 = 0 ; V_78 < V_51 -> V_79 ; V_78 ++ ) {
V_52 = & V_51 -> V_53 [ V_78 ] ;
if ( V_52 -> V_3 == V_77 -> V_52 -> V_3 )
break;
}
if ( V_78 >= V_51 -> V_79 )
return 0 ;
V_11 = F_26 ( V_52 ) ;
V_73 = V_52 -> V_80 + V_52 -> V_81 - 1 ;
V_74 = V_52 -> V_80 ;
if ( V_77 -> V_57 ) {
if ( V_77 -> V_57 -> V_80 >= V_52 -> V_80
&& V_77 -> V_57 -> V_80 < V_73 )
;
else
return 0 ;
}
V_82:
F_64 (ndd, res) {
if ( strncmp ( V_57 -> V_83 , L_12 , 4 ) != 0 )
continue;
if ( ( V_57 -> V_80 >= V_74 && V_57 -> V_80 < V_73 )
|| ( V_57 -> V_84 >= V_74
&& V_57 -> V_84 <= V_73 ) ) {
V_75 = F_65 ( V_74 , F_13 ( V_73 + 1 , V_57 -> V_84 + 1 ) ) ;
if ( V_75 != V_74 ) {
V_74 = V_75 ;
goto V_82;
}
}
}
if ( V_77 -> V_57 && V_74 > V_77 -> V_57 -> V_80 ) {
V_77 -> V_57 -> V_80 = F_65 ( V_77 -> V_57 -> V_80 , V_74 ) ;
if ( V_77 -> V_57 -> V_80 > V_77 -> V_57 -> V_84 )
V_77 -> V_57 -> V_84 = V_77 -> V_57 -> V_80 - 1 ;
return 1 ;
}
V_77 -> V_85 -= V_74 - V_52 -> V_80 ;
return 0 ;
}
T_4 F_66 ( struct V_51 * V_51 )
{
struct V_18 * V_18 = F_8 ( & V_51 -> V_2 ) ;
struct V_52 * V_52 = & V_51 -> V_53 [ 0 ] ;
struct V_10 * V_11 = F_26 ( V_52 ) ;
struct V_76 V_77 = {
. V_52 = V_52 ,
. V_85 = V_52 -> V_81 ,
. V_57 = NULL ,
} ;
struct V_56 * V_57 ;
if ( ! V_11 )
return 0 ;
F_67 ( & V_18 -> V_2 , & V_77 , F_61 ) ;
F_64 (ndd, res) {
if ( strncmp ( V_57 -> V_83 , L_13 , 3 ) != 0 )
continue;
V_77 . V_85 -= F_68 ( V_57 ) ;
}
return V_77 . V_85 ;
}
T_4 F_69 ( struct V_51 * V_51 ,
struct V_52 * V_52 , T_4 * V_86 )
{
T_4 V_87 , V_73 , V_64 = 0 , V_85 , V_74 ;
struct V_10 * V_11 = F_26 ( V_52 ) ;
struct V_56 * V_57 ;
const char * V_88 ;
if ( ! V_11 )
return 0 ;
V_87 = V_52 -> V_80 ;
V_73 = V_87 + V_52 -> V_81 - 1 ;
V_74 = F_65 ( V_87 , V_73 + 1 - * V_86 ) ;
F_64 (ndd, res) {
if ( V_57 -> V_80 >= V_87 && V_57 -> V_80 < V_73 ) {
if ( strncmp ( V_57 -> V_83 , L_13 , 3 ) == 0 )
V_74 = F_13 ( V_74 ,
F_65 ( V_87 , V_57 -> V_80 ) ) ;
else if ( V_57 -> V_84 > V_73 ) {
V_88 = L_14 ;
goto V_89;
} else
V_64 += F_68 ( V_57 ) ;
} else if ( V_57 -> V_84 >= V_87 && V_57 -> V_84 <= V_73 ) {
if ( strncmp ( V_57 -> V_83 , L_13 , 3 ) == 0 ) {
V_74 = V_87 ;
} else
V_64 += F_68 ( V_57 ) ;
} else if ( V_87 > V_57 -> V_80 && V_87 < V_57 -> V_84 ) {
V_64 += V_52 -> V_81 ;
V_74 = V_87 ;
}
}
* V_86 = V_73 + 1 - V_74 ;
V_85 = V_74 - V_87 ;
if ( V_64 < V_85 )
return V_85 - V_64 ;
return 0 ;
V_89:
F_70 ( V_51 , V_11 , V_57 , L_4 , V_88 ) ;
return 0 ;
}
void F_34 ( struct V_10 * V_11 , struct V_56 * V_57 )
{
F_27 ( ! F_28 ( V_11 -> V_2 ) ) ;
F_14 ( V_57 -> V_83 ) ;
F_71 ( & V_11 -> V_90 , V_57 -> V_80 , F_68 ( V_57 ) ) ;
}
struct V_56 * F_72 ( struct V_10 * V_11 ,
struct V_91 * V_92 , T_4 V_80 ,
T_4 V_93 )
{
char * V_83 = F_73 ( V_92 , sizeof( * V_92 ) , V_32 ) ;
struct V_56 * V_57 ;
if ( ! V_83 )
return NULL ;
F_27 ( ! F_28 ( V_11 -> V_2 ) ) ;
V_57 = F_74 ( & V_11 -> V_90 , V_80 , V_93 , V_83 , 0 ) ;
if ( ! V_57 )
F_14 ( V_83 ) ;
return V_57 ;
}
T_4 F_75 ( struct V_10 * V_11 ,
struct V_91 * V_92 )
{
T_4 V_94 = 0 ;
struct V_56 * V_57 ;
F_64 (ndd, res)
if ( strcmp ( V_57 -> V_83 , V_92 -> V_47 ) == 0 )
V_94 += F_68 ( V_57 ) ;
return V_94 ;
}
static int F_76 ( struct V_1 * V_2 , void * V_95 )
{
int * V_96 = V_95 ;
if ( F_21 ( V_2 ) )
( * V_96 ) ++ ;
return 0 ;
}
int F_77 ( struct V_18 * V_18 , int V_97 )
{
int V_96 = 0 ;
F_78 () ;
F_67 ( & V_18 -> V_2 , & V_96 , F_76 ) ;
F_5 ( & V_18 -> V_2 , L_15 , V_14 , V_96 ) ;
if ( V_96 != V_97 )
return - V_8 ;
return 0 ;
}
void T_5 F_79 ( void )
{
F_80 ( & V_46 ) ;
}
