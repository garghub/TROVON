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
V_25 = V_17 + V_9 -> V_30 ;
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
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
return snprintf ( V_5 , V_11 , L_13 , V_9 -> V_35 ) ;
}
static int
F_8 ( struct V_8 * V_9 )
{
return F_9 ( & F_10 ( V_9 -> V_36 ) -> V_37 , & V_38 ) ;
}
void
F_11 ( struct V_8 * V_9 )
{
F_12 ( & F_10 ( V_9 -> V_36 ) -> V_37 , & V_38 ) ;
}
static int
F_13 ( struct V_39 * V_40 , T_2 V_41 )
{
struct V_8 * V_9 = V_40 -> V_42 -> V_10 ;
T_3 V_12 ;
if ( ! F_14 ( V_9 ) ) {
F_15 ( L_14 ,
V_43 ) ;
F_16 ( 1 ) ;
return - V_44 ;
}
if ( ! ( V_9 -> V_12 & V_13 ) || V_9 -> V_12 & V_45 )
return - V_44 ;
F_17 ( & V_46 ) ;
F_18 ( & V_9 -> V_47 , V_12 ) ;
if ( V_9 -> V_12 & V_13 && ! ( V_9 -> V_12 & V_45 ) ) {
V_9 -> V_15 ++ ;
F_19 ( & V_9 -> V_47 , V_12 ) ;
F_20 ( & V_46 ) ;
return 0 ;
}
F_19 ( & V_9 -> V_47 , V_12 ) ;
F_20 ( & V_46 ) ;
return - V_44 ;
}
static void
F_21 ( struct V_6 * V_7 , T_2 V_41 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
T_3 V_12 ;
F_18 ( & V_9 -> V_47 , V_12 ) ;
if ( -- V_9 -> V_15 == 0 ) {
F_19 ( & V_9 -> V_47 , V_12 ) ;
F_22 ( V_9 -> V_48 , V_9 -> V_49 ) ;
return;
}
F_19 ( & V_9 -> V_47 , V_12 ) ;
}
static void
F_23 ( struct V_50 * V_51 )
{
struct V_8 * V_9 ;
struct V_52 * V_53 ;
V_9 = V_51 -> V_54 ;
if ( ( V_9 -> V_12 & V_13 ) == 0 ) {
F_24 ( L_15 ,
V_9 -> V_48 , V_9 -> V_49 ) ;
while ( ( V_53 = F_25 ( V_51 ) ) ) {
F_26 ( V_53 ) ;
F_27 ( V_9 , V_53 , 1 ) ;
}
return;
}
F_28 ( V_9 ) ;
}
static int
F_29 ( struct V_39 * V_40 , struct V_55 * V_56 )
{
struct V_8 * V_9 = V_40 -> V_42 -> V_10 ;
if ( ( V_9 -> V_12 & V_13 ) == 0 ) {
F_30 ( V_57 L_16 ) ;
return - V_44 ;
}
V_56 -> V_58 = V_9 -> V_56 . V_58 ;
V_56 -> V_59 = V_9 -> V_56 . V_59 ;
V_56 -> V_60 = V_9 -> V_56 . V_60 ;
return 0 ;
}
static int
F_31 ( struct V_39 * V_40 , T_2 V_41 , T_4 V_61 , T_3 V_62 )
{
struct V_8 * V_9 ;
if ( ! V_62 )
return - V_63 ;
V_9 = V_40 -> V_42 -> V_10 ;
if ( ( V_9 -> V_12 & V_13 ) == 0 ) {
F_32 ( L_16 ) ;
return - V_44 ;
}
if ( V_61 == V_64 ) {
if ( ! F_33 ( ( void V_65 * ) V_62 , & V_9 -> V_66 ,
sizeof( V_9 -> V_66 ) ) )
return 0 ;
return - V_67 ;
}
if ( V_61 != V_68 )
F_34 ( L_17 , V_61 ) ;
return - V_69 ;
}
void
F_35 ( void * V_70 )
{
struct V_8 * V_9 = V_70 ;
struct V_6 * V_36 ;
T_5 * V_71 ;
struct V_50 * V_51 ;
enum { V_72 = 1024 , V_73 = V_72 * V_72 , V_74 = 2 * V_73 , };
T_3 V_12 ;
int V_75 = 0 ;
F_18 ( & V_9 -> V_47 , V_12 ) ;
if ( V_9 -> V_12 & V_76
&& ! ( V_9 -> V_12 & V_45 )
&& ! ( V_9 -> V_12 & V_77 ) )
V_9 -> V_12 |= V_77 ;
else
V_75 = 1 ;
F_19 ( & V_9 -> V_47 , V_12 ) ;
if ( V_75 )
return;
V_36 = F_36 ( V_78 ) ;
if ( V_36 == NULL ) {
F_32 ( L_18 ,
V_9 -> V_48 , V_9 -> V_49 ) ;
goto V_79;
}
V_71 = F_37 ( V_80 , V_81 , V_82 ,
V_83 ) ;
if ( V_71 == NULL ) {
F_30 ( V_57 L_19 ,
V_9 -> V_48 , V_9 -> V_49 ) ;
goto V_84;
}
V_51 = F_38 ( F_23 , & V_9 -> V_47 ) ;
if ( V_51 == NULL ) {
F_32 ( L_20 ,
V_9 -> V_48 , V_9 -> V_49 ) ;
goto V_85;
}
F_18 ( & V_9 -> V_47 , V_12 ) ;
F_16 ( ! ( V_9 -> V_12 & V_77 ) ) ;
F_16 ( ! ( V_9 -> V_12 & V_76 ) ) ;
F_16 ( V_9 -> V_12 & V_45 ) ;
F_16 ( V_9 -> V_36 ) ;
F_16 ( V_9 -> V_12 & V_13 ) ;
F_39 ( V_51 , V_86 ) ;
V_51 -> V_87 . V_33 = L_21 ;
V_51 -> V_87 . V_88 = V_74 / V_89 ;
V_9 -> V_90 = V_71 ;
V_9 -> V_91 = V_36 -> V_92 = V_51 ;
V_51 -> V_54 = V_9 ;
V_9 -> V_36 = V_36 ;
if ( V_93 )
F_39 ( V_51 , V_93 ) ;
V_36 -> V_94 = V_95 ;
V_36 -> V_96 = V_9 -> V_97 ;
V_36 -> V_98 = & V_99 ;
V_36 -> V_10 = V_9 ;
F_40 ( V_36 , V_9 -> V_100 ) ;
snprintf ( V_36 -> V_101 , sizeof V_36 -> V_101 , L_22 ,
V_9 -> V_48 , V_9 -> V_49 ) ;
V_9 -> V_12 &= ~ V_76 ;
V_9 -> V_12 |= V_13 ;
F_19 ( & V_9 -> V_47 , V_12 ) ;
F_41 ( V_36 ) ;
F_8 ( V_9 ) ;
F_18 ( & V_9 -> V_47 , V_12 ) ;
F_16 ( ! ( V_9 -> V_12 & V_77 ) ) ;
V_9 -> V_12 &= ~ V_77 ;
F_19 ( & V_9 -> V_47 , V_12 ) ;
return;
V_85:
F_42 ( V_71 ) ;
V_84:
F_43 ( V_36 ) ;
V_79:
F_18 ( & V_9 -> V_47 , V_12 ) ;
V_9 -> V_12 &= ~ V_77 ;
F_44 ( & V_9 -> V_102 ) ;
F_19 ( & V_9 -> V_47 , V_12 ) ;
}
void
F_45 ( void )
{
F_46 ( V_83 ) ;
}
int T_6
F_47 ( void )
{
V_83 = F_48 ( L_23 ,
sizeof( struct V_103 ) ,
0 , 0 , NULL ) ;
if ( V_83 == NULL )
return - V_104 ;
return 0 ;
}
