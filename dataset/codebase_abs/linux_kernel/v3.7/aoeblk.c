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
static void
F_19 ( struct V_47 * V_48 )
{
struct V_8 * V_9 ;
struct V_49 * V_50 ;
V_9 = V_48 -> V_51 ;
if ( ( V_9 -> V_12 & V_13 ) == 0 ) {
F_20 ( L_13 ,
V_9 -> V_45 , V_9 -> V_46 ) ;
while ( ( V_50 = F_21 ( V_48 ) ) ) {
F_22 ( V_50 ) ;
F_23 ( V_9 , V_50 , 1 ) ;
}
return;
}
F_24 ( V_9 ) ;
}
static int
F_25 ( struct V_38 * V_39 , struct V_52 * V_53 )
{
struct V_8 * V_9 = V_39 -> V_41 -> V_10 ;
if ( ( V_9 -> V_12 & V_13 ) == 0 ) {
F_26 ( V_54 L_14 ) ;
return - V_44 ;
}
V_53 -> V_55 = V_9 -> V_53 . V_55 ;
V_53 -> V_56 = V_9 -> V_53 . V_56 ;
V_53 -> V_57 = V_9 -> V_53 . V_57 ;
return 0 ;
}
void
F_27 ( void * V_58 )
{
struct V_8 * V_9 = V_58 ;
struct V_6 * V_35 ;
T_4 * V_59 ;
struct V_47 * V_48 ;
enum { V_60 = 1024 , V_61 = V_60 * V_60 , V_62 = 2 * V_61 , };
T_3 V_12 ;
V_35 = F_28 ( V_63 ) ;
if ( V_35 == NULL ) {
F_29 ( L_15 ,
V_9 -> V_45 , V_9 -> V_46 ) ;
goto V_64;
}
V_59 = F_30 ( V_65 , V_66 , V_67 ,
V_68 ) ;
if ( V_59 == NULL ) {
F_26 ( V_54 L_16 ,
V_9 -> V_45 , V_9 -> V_46 ) ;
goto V_69;
}
V_48 = F_31 ( F_19 , & V_9 -> V_43 ) ;
if ( V_48 == NULL ) {
F_29 ( L_17 ,
V_9 -> V_45 , V_9 -> V_46 ) ;
F_32 ( V_59 ) ;
goto V_69;
}
V_9 -> V_70 = F_33 ( V_71 ) ;
if ( ! V_9 -> V_70 )
goto V_72;
V_9 -> V_70 -> V_73 . V_33 = L_18 ;
if ( F_34 ( & V_9 -> V_70 -> V_73 ) )
goto V_74;
F_14 ( & V_9 -> V_43 , V_12 ) ;
F_35 ( V_9 -> V_70 , V_75 ) ;
V_48 -> V_73 . V_76 = V_62 / V_77 ;
V_9 -> V_78 = V_59 ;
V_9 -> V_70 = V_35 -> V_79 = V_48 ;
V_48 -> V_51 = V_9 ;
V_9 -> V_35 = V_35 ;
V_35 -> V_80 = V_81 ;
V_35 -> V_82 = V_9 -> V_83 ;
V_35 -> V_84 = & V_85 ;
V_35 -> V_10 = V_9 ;
F_36 ( V_35 , V_9 -> V_86 ) ;
snprintf ( V_35 -> V_87 , sizeof V_35 -> V_87 , L_19 ,
V_9 -> V_45 , V_9 -> V_46 ) ;
V_9 -> V_12 &= ~ V_88 ;
V_9 -> V_12 |= V_13 ;
F_15 ( & V_9 -> V_43 , V_12 ) ;
F_37 ( V_35 ) ;
F_7 ( V_9 ) ;
return;
V_74:
F_38 ( V_9 -> V_70 ) ;
V_9 -> V_70 = NULL ;
V_72:
F_32 ( V_9 -> V_78 ) ;
V_69:
F_39 ( V_35 ) ;
V_64:
F_14 ( & V_9 -> V_43 , V_12 ) ;
V_9 -> V_12 &= ~ V_88 ;
F_15 ( & V_9 -> V_43 , V_12 ) ;
}
void
F_40 ( void )
{
F_41 ( V_68 ) ;
}
int T_5
F_42 ( void )
{
V_68 = F_43 ( L_20 ,
sizeof( struct V_89 ) ,
0 , 0 , NULL ) ;
if ( V_68 == NULL )
return - V_90 ;
return 0 ;
}
