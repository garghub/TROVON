static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
if ( ! V_2 )
return - V_4 ;
V_3 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_3 -> V_6 )
return - V_7 ;
if ( ! F_3 ( V_8 , & V_3 -> V_6 ) )
return - V_7 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_9 = F_1 ( V_2 ) ;
if ( V_9 && V_2 )
F_5 ( V_2 -> V_5 , L_1 ,
F_6 ( 0 ) , V_10 , V_9 ) ;
return V_9 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = & V_2 -> V_13 ;
struct V_14 * V_14 = F_8 ( V_2 -> V_5 ) ;
struct V_15 * V_16 ;
int V_9 = F_4 ( V_2 ) ;
if ( V_9 )
return V_9 ;
if ( V_12 -> V_17 )
return 0 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_16 = V_14 -> V_16 ;
return V_16 -> V_18 ( V_16 , F_2 ( V_2 -> V_5 ) ,
V_19 , V_12 , sizeof( * V_12 ) , NULL ) ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_8 ( V_2 -> V_5 ) ;
struct V_20 * V_12 ;
struct V_15 * V_16 ;
int V_9 = F_4 ( V_2 ) ;
T_1 V_21 , V_17 ;
T_2 V_22 ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_23 )
return 0 ;
if ( V_2 -> V_13 . V_24 || V_2 -> V_13 . V_25 == 0
|| V_2 -> V_13 . V_17 < V_26 ) {
F_5 ( V_2 -> V_5 , L_2 ,
V_2 -> V_13 . V_25 , V_2 -> V_13 . V_17 ) ;
return - V_7 ;
}
V_2 -> V_23 = F_10 ( V_2 -> V_13 . V_17 , V_27 ) ;
if ( ! V_2 -> V_23 )
V_2 -> V_23 = F_11 ( V_2 -> V_13 . V_17 ) ;
if ( ! V_2 -> V_23 )
return - V_28 ;
V_21 = F_12 ( T_1 , V_29 , V_2 -> V_13 . V_25 ) ;
V_12 = F_13 ( V_21 + sizeof( * V_12 ) , V_27 ) ;
if ( ! V_12 )
return - V_28 ;
V_16 = V_14 -> V_16 ;
for ( V_17 = V_2 -> V_13 . V_17 , V_22 = 0 ;
V_17 ; V_17 -= V_12 -> V_30 ,
V_22 += V_12 -> V_30 ) {
V_12 -> V_30 = F_14 ( V_17 , V_21 ) ;
V_12 -> V_31 = V_22 ;
V_9 = V_16 -> V_18 ( V_16 , F_2 ( V_2 -> V_5 ) ,
V_8 , V_12 ,
V_12 -> V_30 + sizeof( * V_12 ) , NULL ) ;
if ( V_9 || V_12 -> V_24 ) {
V_9 = - V_7 ;
break;
}
memcpy ( V_2 -> V_23 + V_22 , V_12 -> V_32 , V_12 -> V_30 ) ;
}
F_5 ( V_2 -> V_5 , L_3 , V_10 , V_22 , V_9 ) ;
F_15 ( V_12 ) ;
return V_9 ;
}
int F_16 ( struct V_1 * V_2 , T_2 V_22 ,
void * V_33 , T_2 V_34 )
{
int V_9 = F_4 ( V_2 ) ;
T_2 V_21 , V_35 ;
struct V_36 * V_12 ;
struct V_14 * V_14 = F_8 ( V_2 -> V_5 ) ;
struct V_15 * V_16 = V_14 -> V_16 ;
if ( V_9 )
return V_9 ;
if ( ! V_2 -> V_23 )
return - V_7 ;
if ( V_22 + V_34 > V_2 -> V_13 . V_17 )
return - V_7 ;
V_21 = F_12 ( T_1 , V_29 , V_34 ) ;
V_21 = F_12 ( T_1 , V_21 , V_2 -> V_13 . V_25 ) ;
V_12 = F_13 ( V_21 + sizeof( * V_12 ) + sizeof( T_1 ) , V_27 ) ;
if ( ! V_12 )
return - V_28 ;
for ( V_35 = 0 ; V_34 ; V_34 -= V_12 -> V_30 ,
V_35 += V_12 -> V_30 ) {
T_2 V_37 ;
T_1 * V_24 ;
V_12 -> V_31 = V_22 + V_35 ;
V_12 -> V_30 = F_14 ( V_21 , V_34 ) ;
memcpy ( V_12 -> V_38 , V_33 + V_35 , V_12 -> V_30 ) ;
V_37 = sizeof( * V_12 ) + V_12 -> V_30 + sizeof( T_1 ) ;
V_24 = ( ( void * ) V_12 ) + V_37 - sizeof( T_1 ) ;
V_9 = V_16 -> V_18 ( V_16 , F_2 ( V_2 -> V_5 ) ,
V_39 , V_12 , V_37 , NULL ) ;
if ( V_9 || * V_24 ) {
V_9 = V_9 ? V_9 : - V_7 ;
break;
}
}
F_15 ( V_12 ) ;
return V_9 ;
}
static void F_17 ( struct V_40 * V_5 )
{
struct V_3 * V_3 = F_2 ( V_5 ) ;
F_18 ( & V_41 , V_3 -> V_42 ) ;
F_15 ( V_3 ) ;
}
bool F_19 ( struct V_40 * V_5 )
{
return V_5 -> type == & V_43 ;
}
struct V_3 * F_2 ( struct V_40 * V_5 )
{
struct V_3 * V_3 = F_20 ( V_5 , struct V_3 , V_5 ) ;
F_21 ( ! F_19 ( V_5 ) ) ;
return V_3 ;
}
struct V_3 * F_22 ( struct V_44 * V_45 )
{
struct V_46 * V_46 = & V_45 -> V_46 ;
struct V_47 * V_47 = & V_46 -> V_48 [ 0 ] ;
return V_47 -> V_3 ;
}
struct V_1 * F_23 ( struct V_47 * V_47 )
{
struct V_3 * V_3 = V_47 -> V_3 ;
F_24 ( ! F_25 ( & V_3 -> V_5 ) ) ;
return F_26 ( & V_3 -> V_5 ) ;
}
void F_27 ( struct V_49 * V_49 )
{
struct V_1 * V_2 = F_20 ( V_49 , F_28 ( * V_2 ) , V_49 ) ;
struct V_40 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 , * V_52 ;
F_5 ( V_5 , L_4 , V_10 ) ;
F_29 ( V_5 ) ;
F_30 (ndd, res, _r)
F_31 ( V_2 , V_51 ) ;
F_32 ( V_5 ) ;
F_33 ( V_2 -> V_23 ) ;
F_15 ( V_2 ) ;
F_34 ( V_5 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_49 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( V_2 )
F_38 ( & V_2 -> V_49 , F_27 ) ;
}
const char * F_39 ( struct V_3 * V_3 )
{
return F_40 ( & V_3 -> V_5 ) ;
}
unsigned long F_41 ( struct V_3 * V_3 )
{
return V_3 -> V_6 ;
}
void * F_42 ( struct V_3 * V_3 )
{
if ( V_3 )
return V_3 -> V_53 ;
return NULL ;
}
static T_3 F_43 ( struct V_40 * V_5 ,
struct V_54 * V_55 , char * V_33 )
{
struct V_3 * V_3 = F_2 ( V_5 ) ;
int V_12 , V_34 = 0 ;
if ( ! V_3 -> V_6 )
return sprintf ( V_33 , L_5 ) ;
F_44 (cmd, &nvdimm->cmd_mask, BITS_PER_LONG)
V_34 += sprintf ( V_33 + V_34 , L_6 , F_45 ( V_12 ) ) ;
V_34 += sprintf ( V_33 + V_34 , L_5 ) ;
return V_34 ;
}
static T_3 F_46 ( struct V_40 * V_5 , struct V_54 * V_55 ,
char * V_33 )
{
struct V_3 * V_3 = F_2 ( V_5 ) ;
F_29 ( V_5 ) ;
F_32 ( V_5 ) ;
return sprintf ( V_33 , L_4 , F_47 ( & V_3 -> V_56 )
? L_7 : L_8 ) ;
}
static T_3 F_48 ( struct V_40 * V_5 ,
struct V_54 * V_55 , char * V_33 )
{
struct V_1 * V_2 = F_26 ( V_5 ) ;
T_3 V_9 ;
T_1 V_57 ;
if ( ! V_2 )
return - V_7 ;
F_29 ( V_5 ) ;
V_57 = F_49 ( V_2 ) ;
if ( V_57 - 1 > V_57 ) {
F_50 ( V_5 , 1 , L_9 ) ;
V_57 = 0 ;
} else
V_57 -- ;
V_9 = sprintf ( V_33 , L_10 , V_57 ) ;
F_32 ( V_5 ) ;
return V_9 ;
}
struct V_3 * F_51 ( struct V_14 * V_14 , void * V_53 ,
const struct V_58 * * V_59 , unsigned long V_60 ,
unsigned long V_6 , int V_61 ,
struct V_50 * V_62 )
{
struct V_3 * V_3 = F_13 ( sizeof( * V_3 ) , V_27 ) ;
struct V_40 * V_5 ;
if ( ! V_3 )
return NULL ;
V_3 -> V_42 = F_52 ( & V_41 , 0 , 0 , V_27 ) ;
if ( V_3 -> V_42 < 0 ) {
F_15 ( V_3 ) ;
return NULL ;
}
V_3 -> V_53 = V_53 ;
V_3 -> V_60 = V_60 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_61 = V_61 ;
V_3 -> V_62 = V_62 ;
F_53 ( & V_3 -> V_56 , 0 ) ;
V_5 = & V_3 -> V_5 ;
F_54 ( V_5 , L_11 , V_3 -> V_42 ) ;
V_5 -> V_63 = & V_14 -> V_5 ;
V_5 -> type = & V_43 ;
V_5 -> V_64 = F_55 ( V_65 , V_3 -> V_42 ) ;
V_5 -> V_59 = V_59 ;
F_56 ( V_5 ) ;
return V_3 ;
}
T_4 F_57 ( struct V_47 * V_47 )
{
struct V_1 * V_2 = F_23 ( V_47 ) ;
T_4 V_66 , V_56 = 0 , V_67 ;
struct V_50 * V_51 ;
if ( ! V_2 )
return 0 ;
V_66 = V_47 -> V_68 + V_47 -> V_69 - 1 ;
F_58 (ndd, res)
if ( V_51 -> V_68 >= V_47 -> V_68 && V_51 -> V_68 < V_66 ) {
T_4 V_70 = F_14 ( V_66 , V_51 -> V_70 ) ;
V_56 += V_70 - V_51 -> V_68 + 1 ;
} else if ( V_51 -> V_70 >= V_47 -> V_68
&& V_51 -> V_70 <= V_66 ) {
V_56 += V_51 -> V_70 - V_47 -> V_68 ;
} else if ( V_47 -> V_68 > V_51 -> V_68
&& V_47 -> V_68 < V_51 -> V_70 ) {
V_56 += V_47 -> V_69 ;
}
V_67 = V_66 - V_47 -> V_68 + 1 ;
if ( V_56 < V_67 )
return V_67 - V_56 ;
return 0 ;
}
T_4 F_59 ( struct V_46 * V_46 ,
struct V_47 * V_47 , T_4 * V_71 )
{
T_4 V_72 , V_66 , V_56 = 0 , V_67 , V_73 ;
struct V_1 * V_2 = F_23 ( V_47 ) ;
struct V_50 * V_51 ;
const char * V_74 ;
if ( ! V_2 )
return 0 ;
V_72 = V_47 -> V_68 ;
V_66 = V_72 + V_47 -> V_69 - 1 ;
V_73 = F_60 ( V_72 , V_66 + 1 - * V_71 ) ;
F_58 (ndd, res)
if ( V_51 -> V_68 >= V_72 && V_51 -> V_68 < V_66 ) {
if ( strncmp ( V_51 -> V_75 , L_12 , 3 ) == 0 )
V_73 = F_14 ( V_73 , V_51 -> V_68 ) ;
else if ( V_51 -> V_68 != V_72 ) {
V_74 = L_13 ;
goto V_76;
} else {
if ( V_56 ) {
V_74 = L_14 ;
goto V_76;
}
V_56 += F_61 ( V_51 ) ;
continue;
}
} else if ( V_51 -> V_70 >= V_72 && V_51 -> V_70 <= V_66 ) {
if ( strncmp ( V_51 -> V_75 , L_12 , 3 ) == 0 ) {
V_73 = V_72 ;
} else {
V_74 = L_13 ;
goto V_76;
}
} else if ( V_72 > V_51 -> V_68 && V_72 < V_51 -> V_70 ) {
V_56 += V_47 -> V_69 ;
V_73 = V_72 ;
}
* V_71 = V_66 + 1 - V_73 ;
V_67 = V_73 - V_72 ;
if ( V_56 < V_67 )
return V_67 - V_56 ;
return 0 ;
V_76:
F_62 ( V_46 , V_2 , V_51 , L_4 , V_74 ) ;
return 0 ;
}
void F_31 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
F_24 ( ! F_25 ( V_2 -> V_5 ) ) ;
F_15 ( V_51 -> V_75 ) ;
F_63 ( & V_2 -> V_77 , V_51 -> V_68 , F_61 ( V_51 ) ) ;
}
struct V_50 * F_64 ( struct V_1 * V_2 ,
struct V_78 * V_79 , T_4 V_68 ,
T_4 V_80 )
{
char * V_75 = F_65 ( V_79 , sizeof( * V_79 ) , V_27 ) ;
struct V_50 * V_51 ;
if ( ! V_75 )
return NULL ;
F_24 ( ! F_25 ( V_2 -> V_5 ) ) ;
V_51 = F_66 ( & V_2 -> V_77 , V_68 , V_80 , V_75 , 0 ) ;
if ( ! V_51 )
F_15 ( V_75 ) ;
return V_51 ;
}
T_4 F_67 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
T_4 V_81 = 0 ;
struct V_50 * V_51 ;
F_58 (ndd, res)
if ( strcmp ( V_51 -> V_75 , V_79 -> V_42 ) == 0 )
V_81 += F_61 ( V_51 ) ;
return V_81 ;
}
static int F_68 ( struct V_40 * V_5 , void * V_82 )
{
int * V_83 = V_82 ;
if ( F_19 ( V_5 ) )
( * V_83 ) ++ ;
return 0 ;
}
int F_69 ( struct V_14 * V_14 , int V_84 )
{
int V_83 = 0 ;
F_70 () ;
F_71 ( & V_14 -> V_5 , & V_83 , F_68 ) ;
F_5 ( & V_14 -> V_5 , L_15 , V_10 , V_83 ) ;
if ( V_83 != V_84 )
return - V_7 ;
return 0 ;
}
void T_5 F_72 ( void )
{
F_73 ( & V_41 ) ;
}
