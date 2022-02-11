static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return snprintf ( V_5 , V_11 ,
L_1 ,
( V_9 -> V_12 & V_13 ) ? L_2 : L_3 ,
( V_9 -> V_12 & V_14 ) ? L_4 :
( V_9 -> V_15 && ! ( V_9 -> V_12 & V_13 ) ) ? L_5 : L_6 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_16 * V_17 = V_9 -> V_18 [ 0 ] ;
if ( V_17 == NULL )
return snprintf ( V_5 , V_11 , L_7 ) ;
return snprintf ( V_5 , V_11 , L_8 , V_17 -> V_19 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_20 * V_21 [ 8 ] , * * V_22 , * * V_23 , * * V_24 ;
struct V_16 * * V_17 , * * V_25 ;
struct V_26 * V_27 , * V_28 ;
char * V_29 ;
memset ( V_21 , 0 , sizeof V_21 ) ;
V_22 = V_21 ;
V_24 = V_22 + F_5 ( V_21 ) ;
V_17 = V_9 -> V_18 ;
V_25 = V_17 + V_30 ;
for (; V_17 < V_25 && * V_17 ; V_17 ++ ) {
V_27 = ( * V_17 ) -> V_31 ;
V_28 = V_27 + V_32 ;
for (; V_27 < V_28 && V_27 -> V_22 ; V_27 ++ ) {
for ( V_23 = V_21 ; V_23 < V_22 ; V_23 ++ )
if ( * V_23 == V_27 -> V_22 )
break;
if ( V_23 == V_22 && V_22 != V_24 )
* V_22 ++ = V_27 -> V_22 ;
}
}
V_24 = V_22 ;
V_22 = V_21 ;
if ( * V_22 == NULL )
return snprintf ( V_5 , V_11 , L_7 ) ;
for ( V_29 = V_5 ; V_22 < V_24 ; V_22 ++ )
V_29 += snprintf ( V_29 , V_11 - ( V_29 - V_5 ) , L_9 ,
V_29 == V_5 ? L_6 : L_10 , ( * V_22 ) -> V_33 ) ;
V_29 += snprintf ( V_29 , V_11 - ( V_29 - V_5 ) , L_11 ) ;
return V_29 - V_5 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return snprintf ( V_5 , V_11 , L_12 , ( unsigned int ) V_9 -> V_34 ) ;
}
static int
F_7 ( struct V_8 * V_9 )
{
return F_8 ( & F_9 ( V_9 -> V_35 ) -> V_36 , & V_37 ) ;
}
void
F_10 ( struct V_8 * V_9 )
{
F_11 ( & F_9 ( V_9 -> V_35 ) -> V_36 , & V_37 ) ;
}
static int
F_12 ( struct V_38 * V_39 , T_2 V_40 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_10 ;
T_3 V_12 ;
F_13 ( & V_42 ) ;
F_14 ( & V_9 -> V_43 , V_12 ) ;
if ( V_9 -> V_12 & V_13 ) {
V_9 -> V_15 ++ ;
F_15 ( & V_9 -> V_43 , V_12 ) ;
F_16 ( & V_42 ) ;
return 0 ;
}
F_15 ( & V_9 -> V_43 , V_12 ) ;
F_16 ( & V_42 ) ;
return - V_44 ;
}
static int
F_17 ( struct V_6 * V_7 , T_2 V_40 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
T_3 V_12 ;
F_14 ( & V_9 -> V_43 , V_12 ) ;
if ( -- V_9 -> V_15 == 0 ) {
F_15 ( & V_9 -> V_43 , V_12 ) ;
F_18 ( V_9 -> V_45 , V_9 -> V_46 ) ;
return 0 ;
}
F_15 ( & V_9 -> V_43 , V_12 ) ;
return 0 ;
}
static int
F_19 ( struct V_47 * V_48 , struct V_49 * V_49 )
{
struct V_50 V_51 ;
struct V_8 * V_9 ;
struct V_52 * V_52 ;
T_3 V_12 ;
F_20 ( V_48 , & V_49 ) ;
if ( V_49 == NULL ) {
F_21 ( V_53 L_13 ) ;
F_22 () ;
return 0 ;
}
V_9 = V_49 -> V_54 -> V_41 -> V_10 ;
if ( V_9 == NULL ) {
F_21 ( V_53 L_14 ) ;
F_22 () ;
F_23 ( V_49 , - V_55 ) ;
return 0 ;
} else if ( V_49 -> V_56 == NULL ) {
F_21 ( V_53 L_15 ) ;
F_22 () ;
F_23 ( V_49 , - V_55 ) ;
return 0 ;
}
V_52 = F_24 ( V_9 -> V_57 , V_58 ) ;
if ( V_52 == NULL ) {
F_21 ( V_59 L_16 ) ;
F_23 ( V_49 , - V_60 ) ;
return 0 ;
}
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
F_25 ( & V_52 -> V_61 ) ;
V_52 -> V_62 = V_63 ;
V_52 -> V_49 = V_49 ;
V_52 -> V_64 = V_49 -> V_65 ;
V_52 -> V_66 = V_49 -> V_67 ;
V_52 -> V_68 = & V_49 -> V_56 [ V_49 -> V_69 ] ;
V_52 -> V_70 = V_52 -> V_68 -> V_71 ;
F_26 ( V_52 -> V_70 == 0 ) ;
V_52 -> V_72 = V_52 -> V_68 -> V_73 ;
F_14 ( & V_9 -> V_43 , V_12 ) ;
if ( ( V_9 -> V_12 & V_13 ) == 0 ) {
F_27 ( L_17 ,
V_9 -> V_45 , V_9 -> V_46 ) ;
F_15 ( & V_9 -> V_43 , V_12 ) ;
F_28 ( V_52 , V_9 -> V_57 ) ;
F_23 ( V_49 , - V_55 ) ;
return 0 ;
}
F_29 ( & V_52 -> V_61 , & V_9 -> V_74 ) ;
F_30 ( V_9 ) ;
F_31 ( & V_51 ) ;
F_32 ( & V_9 -> V_75 , & V_51 ) ;
F_15 ( & V_9 -> V_43 , V_12 ) ;
F_33 ( & V_51 ) ;
return 0 ;
}
static int
F_34 ( struct V_38 * V_39 , struct V_76 * V_77 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_10 ;
if ( ( V_9 -> V_12 & V_13 ) == 0 ) {
F_21 ( V_53 L_18 ) ;
return - V_44 ;
}
V_77 -> V_78 = V_9 -> V_77 . V_78 ;
V_77 -> V_79 = V_9 -> V_77 . V_79 ;
V_77 -> V_80 = V_9 -> V_77 . V_80 ;
return 0 ;
}
void
F_35 ( void * V_81 )
{
struct V_8 * V_9 = V_81 ;
struct V_6 * V_35 ;
T_3 V_12 ;
V_35 = F_36 ( V_82 ) ;
if ( V_35 == NULL ) {
F_21 ( V_53
L_19 ,
V_9 -> V_45 , V_9 -> V_46 ) ;
goto V_83;
}
V_9 -> V_57 = F_37 ( V_84 , V_85 ) ;
if ( V_9 -> V_57 == NULL ) {
F_21 ( V_53 L_20 ,
V_9 -> V_45 , V_9 -> V_46 ) ;
goto V_86;
}
V_9 -> V_87 = F_38 ( V_88 ) ;
if ( ! V_9 -> V_87 )
goto V_89;
F_39 ( V_9 -> V_87 , F_19 ) ;
V_9 -> V_87 -> V_90 . V_33 = L_21 ;
if ( F_40 ( & V_9 -> V_87 -> V_90 ) )
goto V_91;
F_14 ( & V_9 -> V_43 , V_12 ) ;
V_35 -> V_92 = V_93 ;
V_35 -> V_94 = V_9 -> V_95 * V_82 ;
V_35 -> V_96 = & V_97 ;
V_35 -> V_10 = V_9 ;
F_41 ( V_35 , V_9 -> V_98 ) ;
snprintf ( V_35 -> V_99 , sizeof V_35 -> V_99 , L_22 ,
V_9 -> V_45 , V_9 -> V_46 ) ;
V_35 -> V_51 = V_9 -> V_87 ;
V_9 -> V_35 = V_35 ;
V_9 -> V_12 &= ~ V_100 ;
V_9 -> V_12 |= V_13 ;
F_15 ( & V_9 -> V_43 , V_12 ) ;
F_42 ( V_35 ) ;
F_7 ( V_9 ) ;
return;
V_91:
F_43 ( V_9 -> V_87 ) ;
V_9 -> V_87 = NULL ;
V_89:
F_44 ( V_9 -> V_57 ) ;
V_86:
F_45 ( V_35 ) ;
V_83:
F_14 ( & V_9 -> V_43 , V_12 ) ;
V_9 -> V_12 &= ~ V_100 ;
F_15 ( & V_9 -> V_43 , V_12 ) ;
}
void
F_46 ( void )
{
F_47 ( V_85 ) ;
}
int T_4
F_48 ( void )
{
V_85 = F_49 ( L_23 ,
sizeof( struct V_52 ) ,
0 , 0 , NULL ) ;
if ( V_85 == NULL )
return - V_60 ;
return 0 ;
}
