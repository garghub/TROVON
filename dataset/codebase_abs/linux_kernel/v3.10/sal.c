static long
F_1 ( void )
{
return - 1 ;
}
const char *
F_2 ( long V_1 )
{
const char * V_2 ;
switch ( V_1 ) {
case 0 : V_2 = L_1 ; break;
case 1 : V_2 = L_2
L_3 ; break;
case - 1 : V_2 = L_4 ; break;
case - 2 : V_2 = L_5 ; break;
case - 3 : V_2 = L_6 ; break;
case - 4 : V_2 = L_7 ; break;
case - 5 : V_2 = L_8 ; break;
case - 6 : V_2 = L_9 ; break;
case - 7 : V_2 = L_10 ; break;
case - 8 : V_2 = L_11 ; break;
case - 9 : V_2 = L_12 ; break;
case - 10 : V_2 = L_13 ; break;
case - 11 : V_2 = L_14 ; break;
case - 12 : V_2 = L_15 ; break;
case - 13 : V_2 = L_16
L_17 ; break;
case - 14 : V_2 = L_18
L_19 ; break;
case - 15 : V_2 = L_20
L_21 ; break;
case - 16 : V_2 = L_22
L_23 ; break;
case - 17 : V_2 = L_24
L_25 ; break;
case - 18 : V_2 = L_26
L_27 ; break;
case - 19 : V_2 = L_28
L_29 ; break;
case - 20 : V_2 = L_30
L_31
L_32 ; break;
default: V_2 = L_33 ; break;
}
return V_2 ;
}
void T_1
F_3 ( void * V_3 , void * V_4 )
{
V_5 . V_6 = V_3 ;
V_5 . V_4 = V_4 ;
V_7 = ( V_8 ) & V_5 ;
}
static void T_1
F_4 ( struct V_9 * V_10 )
{
V_11 = ( V_10 -> V_12 << 8 ) | V_10 -> V_13 ;
V_14 = ( V_10 -> V_15 << 8 ) | V_10 -> V_16 ;
if ( ( V_11 == F_5 ( 49 , 29 ) )
&& ( V_14 == F_5 ( 49 , 29 ) ) )
{
V_11 = F_5 ( 2 , 8 ) ;
V_14 = F_5 ( 0 , 0 ) ;
}
if ( F_6 ( L_34 ) && ( V_11 == F_5 ( 2 , 9 ) ) )
V_11 = F_5 ( 3 , 2 ) ;
}
static void T_1
F_7 ( void * V_17 )
{
struct V_18 * V_19 = V_17 ;
F_8 ( F_9 ( V_19 -> V_20 ) ) ;
F_3 ( F_9 ( V_19 -> V_21 ) , F_9 ( V_19 -> V_22 ) ) ;
}
static void T_1
F_10 ( int V_23 )
{
#ifndef F_11
if ( V_24 )
V_25 &= ~ V_23 ;
else
V_25 |= V_23 ;
#else
V_24 = 1 ;
V_25 &= ~ V_23 ;
#endif
}
static void T_1
F_12 ( void * V_17 )
{
struct V_26 * V_27 = V_17 ;
V_28 = V_27 -> V_29 ;
F_13 ( V_30 L_35 ) ;
if ( ! V_28 ) {
F_13 ( L_36 ) ;
return;
}
if ( V_28 & V_31 )
F_13 ( L_37 ) ;
if ( V_28 & V_32 ) {
F_13 ( L_38 ) ;
F_10 ( V_33 ) ;
}
if ( V_28 & V_34 ) {
F_13 ( L_39 ) ;
F_10 ( V_35 ) ;
}
if ( V_28 & V_36 )
F_13 ( L_40 ) ;
F_13 ( L_41 ) ;
}
static void T_1
F_14 ( void * V_17 )
{
struct V_37 * V_38 = V_17 ;
switch ( V_38 -> V_39 ) {
case V_40 :
V_41 = V_38 -> V_42 ;
F_13 ( V_30 L_42
L_43 , V_41 ) ;
break;
default:
F_13 ( V_43 L_44 ) ;
break;
}
}
static void T_1
F_15 ( void )
{
char * V_44 ;
for ( V_44 = V_45 ; * V_44 ; ) {
if ( memcmp ( V_44 , L_45 , 10 ) == 0 ) {
V_24 = 1 ;
F_13 ( L_46 ) ;
break;
} else {
while ( * V_44 != ' ' && * V_44 )
++ V_44 ;
while ( * V_44 == ' ' )
++ V_44 ;
}
}
}
static void T_1 F_14 ( void * V_17 ) { }
static int T_1
F_16 ( char * V_2 )
{
V_46 = 1 ;
return 0 ;
}
void T_1
F_17 ( void )
{
unsigned long V_47 ;
int V_48 ;
T_2 V_42 , V_49 = 3 ;
struct V_50 V_51 ;
if ( V_46 )
return;
V_48 = F_18 () ;
F_19 ( V_47 ) ;
F_20 ( V_48 , V_52 , V_53 , 0 ) ;
while ( ! F_21 ( V_52 ) )
F_22 () ;
F_23 ( V_51 , V_54 , V_49 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_51 . V_1 )
F_13 ( V_43 L_47 , V_51 . V_1 ) ;
if ( F_21 ( V_52 ) ) {
V_42 = F_24 () ;
F_25 () ;
F_26 ( V_42 != V_52 ) ;
} else {
V_46 = 1 ;
F_13 ( V_43 L_48
L_49 ) ;
F_25 () ;
}
F_27 ( V_47 ) ;
F_28 () ;
}
T_3
F_29 ( T_2 V_49 )
{
struct V_50 V_51 ;
if ( V_46 ) {
unsigned long V_47 ;
T_2 V_55 ;
T_3 V_56 ;
V_55 = 0 ;
F_19 ( V_47 ) ;
V_56 = F_30 ( V_49 ,
V_57 , & V_55 , NULL ) ;
F_27 ( V_47 ) ;
return V_56 ;
}
F_23 ( V_51 , V_54 , V_49 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
return V_51 . V_1 ;
}
void T_1
F_31 ( struct V_9 * V_10 )
{
char * V_17 ;
int V_58 ;
if ( ! V_10 ) {
F_13 ( V_59 L_50 ) ;
return;
}
if ( strncmp ( V_10 -> V_60 , L_51 , 4 ) != 0 )
F_13 ( V_43 L_52 ) ;
F_4 ( V_10 ) ;
#ifdef F_32
F_15 () ;
#endif
F_13 ( V_30 L_53 ,
F_33 ( V_11 ) , F_34 ( V_11 ) ,
V_10 -> V_61 , V_10 -> V_62 ,
V_10 -> V_62 [ 0 ] ? L_54 : L_55 ,
F_33 ( V_14 ) , F_34 ( V_14 ) ) ;
V_17 = ( char * ) ( V_10 + 1 ) ;
for ( V_58 = 0 ; V_58 < V_10 -> V_63 ; V_58 ++ ) {
switch ( * V_17 ) {
case V_64 :
F_7 ( V_17 ) ;
break;
case V_65 :
F_12 ( V_17 ) ;
break;
case V_66 :
V_67 = ( V_68 * ) V_17 ;
break;
case V_69 :
F_14 ( V_17 ) ;
break;
}
V_17 += F_35 ( * V_17 ) ;
}
}
int
F_36 ( struct V_50 * V_70 , T_2 V_71 , T_2 V_72 ,
T_2 V_73 , T_2 V_74 , T_2 V_75 , T_2 V_76 , T_2 V_77 , T_2 V_78 )
{
if ( V_71 < V_79 || V_71 > V_80 )
return - 1 ;
F_23 ( * V_70 , V_71 , V_72 , V_73 , V_74 , V_75 , V_76 , V_77 , V_78 ) ;
return 0 ;
}
int
F_37 ( struct V_50 * V_70 , T_2 V_71 , T_2 V_72 ,
T_2 V_73 , T_2 V_74 , T_2 V_75 , T_2 V_76 , T_2 V_77 ,
T_2 V_78 )
{
if ( V_71 < V_79 || V_71 > V_80 )
return - 1 ;
F_38 ( * V_70 , V_71 , V_72 , V_73 , V_74 , V_75 , V_76 , V_77 ,
V_78 ) ;
return 0 ;
}
int
F_39 ( struct V_50 * V_70 , T_2 V_71 ,
T_2 V_72 , T_2 V_73 , T_2 V_74 , T_2 V_75 , T_2 V_76 ,
T_2 V_77 , T_2 V_78 )
{
if ( V_71 < V_79 || V_71 > V_80 )
return - 1 ;
F_40 ( * V_70 , V_71 , V_72 , V_73 , V_74 , V_75 , V_76 , V_77 ,
V_78 ) ;
return 0 ;
}
long
F_41 ( unsigned long V_81 , unsigned long * V_82 ,
unsigned long * V_83 )
{
struct V_50 V_51 ;
F_23 ( V_51 , V_84 , V_81 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
* V_82 = V_51 . V_85 ;
* V_83 = V_51 . V_86 ;
return V_51 . V_1 ;
}
