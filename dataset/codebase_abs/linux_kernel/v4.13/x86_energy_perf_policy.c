void F_1 ( void )
{
fprintf ( V_1 , L_1 , V_2 ) ;
fprintf ( V_1 , L_2 ) ;
fprintf ( V_1 , L_3 ) ;
fprintf ( V_1 , L_4 ) ;
fprintf ( V_1 ,
L_5 ) ;
fprintf ( V_1 , L_6 ) ;
fprintf ( V_1 , L_7 ) ;
fprintf ( V_1 , L_8 , V_2 ) ;
exit ( 1 ) ;
}
int F_2 ( int V_3 )
{
int V_4 ;
if ( ! V_5 )
return V_3 ;
V_4 = V_3 * 255 / V_5 ;
if ( V_6 )
fprintf ( V_1 , L_9 , V_4 , V_3 ) ;
return V_4 ;
}
int F_3 ( int V_4 )
{
int V_3 ;
double V_7 ;
if ( ! V_5 )
return V_4 ;
V_7 = ( double ) V_4 * ( double ) V_5 / 255.0 ;
V_7 = V_7 + 0.5 ;
V_3 = ( int ) V_7 ;
if ( V_6 )
fprintf ( V_1 , L_10 , V_3 , V_4 , V_7 ) ;
return V_3 ;
}
int F_4 ( int V_8 )
{
if ( ! V_9 )
F_5 ( 1 , L_11 ) ;
V_10 = 1 ;
switch ( V_8 ) {
case V_11 :
return V_12 ;
case V_13 :
return V_14 ;
case V_15 :
return V_16 ;
case V_17 :
return V_18 ;
case V_19 :
return V_20 ;
}
if ( V_8 < 0 || V_8 > V_12 )
F_5 ( 1 , L_12 ) ;
return V_8 ;
}
int F_6 ( int V_8 )
{
V_21 = 1 ;
switch ( V_8 ) {
case V_11 :
case V_13 :
case V_15 :
case V_17 :
return V_22 ;
case V_19 :
return V_23 ;
}
return V_8 ;
}
int F_7 ( int V_8 )
{
V_24 = 1 ;
switch ( V_8 ) {
case V_11 :
return V_22 ;
case V_15 :
case V_13 :
case V_17 :
case V_19 :
return V_23 ;
}
return V_8 ;
}
int F_8 ( int V_8 )
{
V_25 = 1 ;
switch ( V_8 ) {
case V_11 :
case V_13 :
case V_17 :
case V_15 :
case V_19 :
return 0 ;
}
return V_8 ;
}
int F_9 ( int V_8 )
{
unsigned int V_26 ;
V_27 = 1 ;
switch ( V_8 ) {
case V_11 :
case V_13 :
case V_15 :
case V_17 :
case V_19 :
return 0 ;
}
if ( V_8 < 0 || V_8 > 1270000000 ) {
fprintf ( V_1 , L_13 ) ;
F_1 () ;
}
for ( V_26 = 0 ; ; ++ V_26 ) {
if ( V_6 )
printf ( L_14 , V_8 , V_26 ) ;
if ( V_8 <= 127 )
break;
V_8 = V_8 / 10 ;
}
if ( V_6 )
fprintf ( V_1 , L_15 , V_8 , V_26 , ( V_26 << 7 ) | V_8 ) ;
return ( V_26 << 7 ) | V_8 ;
}
int F_10 ( int V_8 )
{
V_28 = 1 ;
switch ( V_8 ) {
case V_11 :
return V_29 ;
case V_13 :
return V_30 ;
case V_15 :
case V_17 :
return V_31 ;
case V_19 :
return V_32 ;
}
if ( V_8 < 0 || V_8 > 0xff ) {
fprintf ( V_1 , L_16 ) ;
F_1 () ;
}
return V_8 ;
}
int F_11 ( int V_8 )
{
V_33 = 1 ;
switch ( V_8 ) {
case V_11 :
return 0 ;
case V_15 :
case V_13 :
case V_17 :
case V_19 :
return 1 ;
}
if ( V_8 < 0 || V_8 > 1 ) {
fprintf ( V_1 , L_17 ) ;
F_1 () ;
}
return V_8 ;
}
int F_12 ( char * V_34 )
{
int V_8 ;
char * V_35 ;
if ( ! strncmp ( V_34 , L_18 , 7 ) )
return V_15 ;
if ( ! strncmp ( V_34 , L_19 , 6 ) )
return V_15 ;
if ( ! strncmp ( V_34 , L_20 , 9 ) )
return V_11 ;
if ( ! strncmp ( V_34 , L_21 , 17 ) )
return V_13 ;
if ( ! strncmp ( V_34 , L_22 , 19 ) )
return V_17 ;
if ( ! strncmp ( V_34 , L_23 , 11 ) )
return V_19 ;
V_8 = strtol ( V_34 , & V_35 , 0 ) ;
if ( V_34 == V_35 ) {
fprintf ( V_1 , L_24 , V_34 ) ;
F_1 () ;
}
if ( V_8 == V_36 || V_8 == V_37 )
F_5 ( - 1 , L_25 , V_34 ) ;
if ( V_8 > 0xFF )
F_5 ( - 1 , L_26 , V_8 , V_8 ) ;
if ( V_8 < 0 )
F_5 ( - 1 , L_27 , V_8 , V_8 ) ;
return V_8 ;
}
void F_13 ( char * V_34 )
{
V_38 ++ ;
V_39 = 1 ;
V_40 . V_41 = F_6 ( F_12 ( V_34 ) ) ;
V_40 . V_42 = F_7 ( F_12 ( V_34 ) ) ;
V_40 . V_43 = F_10 ( F_12 ( V_34 ) ) ;
if ( V_9 )
V_44 = F_4 ( F_12 ( V_34 ) ) ;
V_45 = F_11 ( F_12 ( V_34 ) ) ;
V_40 . V_46 = F_8 ( F_12 ( V_34 ) ) ;
V_40 . V_47 = F_9 ( F_12 ( V_34 ) ) ;
}
void F_14 ( void )
{
int V_48 ;
if ( F_15 ( V_49 , V_50 ) == 0 )
F_5 ( 0 , L_28 ) ;
for ( V_48 = 0 ; V_48 <= V_51 ; ++ V_48 ) {
if ( F_16 ( V_48 , V_49 , V_50 ) )
if ( ! F_16 ( V_48 , V_49 , V_52 ) )
F_5 ( 1 , L_29 , V_48 ) ;
}
}
void F_17 ( char * V_34 )
{
char * V_53 , * V_54 ;
int V_48 = 0 ;
if ( V_55 ) {
F_1 () ;
F_5 ( 1 , L_30 ) ;
}
V_50 = F_18 ( ( V_51 + 1 ) ) ;
if ( V_50 == NULL )
F_19 ( 1 , L_31 ) ;
F_20 ( V_49 , V_50 ) ;
for ( V_53 = V_34 ; V_53 && * V_53 ; ) {
if ( * V_53 == ',' ) {
V_53 ++ ;
continue;
}
if ( * V_53 == '-' ) {
int V_56 ;
V_53 ++ ;
V_56 = strtol ( V_53 , & V_54 , 10 ) ;
if ( V_53 == V_54 )
continue;
while ( V_48 <= V_56 ) {
if ( V_48 > V_51 )
F_5 ( 1 , L_32 , V_48 , V_51 ) ;
F_21 ( V_48 , V_49 , V_50 ) ;
V_48 ++ ;
}
V_53 = V_54 ;
continue;
}
if ( strncmp ( V_53 , L_33 , 3 ) == 0 ) {
for ( V_48 = 0 ; V_48 <= V_51 ; V_48 += 1 ) {
if ( F_16 ( V_48 , V_49 , V_52 ) )
F_21 ( V_48 , V_49 , V_50 ) ;
}
V_53 += 3 ;
if ( * V_53 == 0 )
break;
}
if ( strncmp ( V_53 , L_34 , 4 ) == 0 ) {
for ( V_48 = 0 ; V_48 <= V_51 ; V_48 += 2 ) {
if ( F_16 ( V_48 , V_49 , V_52 ) )
F_21 ( V_48 , V_49 , V_50 ) ;
}
V_53 += 4 ;
if ( * V_53 == 0 )
break;
}
if ( strncmp ( V_53 , L_35 , 3 ) == 0 ) {
for ( V_48 = 1 ; V_48 <= V_51 ; V_48 += 2 ) {
if ( F_16 ( V_48 , V_49 , V_52 ) )
F_21 ( V_48 , V_49 , V_50 ) ;
}
V_53 += 3 ;
if ( * V_53 == 0 )
break;
}
V_48 = strtol ( V_53 , & V_54 , 10 ) ;
if ( V_53 == V_54 )
F_5 ( 1 , L_36 , V_53 ) ;
if ( V_48 > V_51 )
F_5 ( 1 , L_32 , V_48 , V_51 ) ;
F_21 ( V_48 , V_49 , V_50 ) ;
V_53 = V_54 ;
}
F_14 () ;
}
void F_22 ( char * V_34 )
{
char * V_53 , * V_54 ;
int V_57 = 0 ;
if ( V_50 ) {
F_1 () ;
F_5 ( 1 , L_37 ) ;
}
V_55 = 0 ;
for ( V_53 = V_34 ; V_53 && * V_53 ; ) {
if ( * V_53 == ',' ) {
V_53 ++ ;
continue;
}
if ( * V_53 == '-' ) {
int V_58 ;
V_53 ++ ;
V_58 = strtol ( V_53 , & V_54 , 10 ) ;
if ( V_53 == V_54 )
continue;
while ( V_57 <= V_58 ) {
if ( V_57 > V_59 )
F_5 ( 1 , L_38 , V_57 , V_59 ) ;
V_55 |= 1 << V_57 ;
V_57 ++ ;
}
V_53 = V_54 ;
continue;
}
if ( strncmp ( V_53 , L_33 , 3 ) == 0 ) {
V_55 = V_60 ;
return;
}
V_57 = strtol ( V_53 , & V_54 , 10 ) ;
if ( V_57 > V_59 )
F_5 ( 1 , L_39 , V_57 , V_59 ) ;
V_55 |= 1 << V_57 ;
V_53 = V_54 ;
}
}
void F_23 ( unsigned long long V_61 , int (F_24)( int ) )
{
int V_62 ;
for ( V_62 = 0 ; V_62 <= V_59 ; ++ V_62 ) {
if ( V_61 & ( 1UL << V_62 ) )
F_24 ( V_62 ) ;
}
}
void F_25 ( void )
{
printf ( L_40 ) ;
}
void F_26 ( int V_63 , char * * V_64 )
{
int V_65 ;
int V_66 = 0 ;
static struct V_67 V_68 [] = {
{ L_33 , V_69 , 0 , 'a' } ,
{ L_41 , V_69 , 0 , 'c' } ,
{ L_42 , V_69 , 0 , 'p' } ,
{ L_43 , V_70 , 0 , 'd' } ,
{ L_44 , V_69 , 0 , 'D' } ,
{ L_45 , V_69 , 0 , 'B' } ,
{ L_46 , V_70 , 0 , 'f' } ,
{ L_47 , V_70 , 0 , 'e' } ,
{ L_48 , V_70 , 0 , 'h' } ,
{ L_49 , V_69 , 0 , 'P' } ,
{ L_50 , V_69 , 0 , 'm' } ,
{ L_51 , V_69 , 0 , 'M' } ,
{ L_52 , V_70 , 0 , 'r' } ,
{ L_53 , V_69 , 0 , 't' } ,
{ L_54 , V_69 , 0 , 'u' } ,
{ L_55 , V_70 , 0 , 'v' } ,
{ L_56 , V_69 , 0 , 'w' } ,
{ 0 , 0 , 0 , 0 }
} ;
V_2 = V_64 [ 0 ] ;
while ( ( V_65 = F_27 ( V_63 , V_64 , L_57 ,
V_68 , & V_66 ) ) != - 1 ) {
switch ( V_65 ) {
case 'a' :
F_13 ( V_71 ) ;
break;
case 'B' :
V_44 = F_4 ( F_12 ( V_71 ) ) ;
break;
case 'c' :
F_17 ( V_71 ) ;
break;
case 'e' :
V_39 = 1 ;
break;
case 'h' :
F_1 () ;
break;
case 'd' :
V_6 ++ ;
V_72 ++ ;
break;
case 'f' :
V_38 ++ ;
break;
case 'D' :
V_40 . V_46 = F_8 ( F_12 ( V_71 ) ) ;
break;
case 'm' :
V_40 . V_41 = F_6 ( F_12 ( V_71 ) ) ;
break;
case 'M' :
V_40 . V_42 = F_7 ( F_12 ( V_71 ) ) ;
break;
case 'p' :
F_22 ( V_71 ) ;
break;
case 'P' :
V_40 . V_43 = F_10 ( F_12 ( V_71 ) ) ;
break;
case 'r' :
break;
case 't' :
V_45 = F_11 ( F_12 ( V_71 ) ) ;
break;
case 'u' :
V_73 ++ ;
if ( atoi ( V_71 ) == 0 )
V_40 . V_74 = 0 ;
else
V_40 . V_74 = 1 ;
break;
case 'v' :
F_25 () ;
exit ( 0 ) ;
break;
case 'w' :
V_40 . V_47 = F_9 ( F_12 ( V_71 ) ) ;
break;
default:
F_1 () ;
}
}
if ( V_63 == V_75 + 1 )
V_44 = F_4 ( F_12 ( V_64 [ V_75 ] ) ) ;
if ( V_63 > V_75 + 1 ) {
fprintf ( V_1 , L_58 , V_64 [ V_75 + 1 ] ) ;
F_1 () ;
}
}
int F_28 ( int V_48 , int V_76 , unsigned long long * V_77 )
{
int V_78 ;
char V_79 [ 32 ] ;
int V_80 ;
sprintf ( V_79 , L_59 , V_48 ) ;
V_80 = F_29 ( V_79 , V_81 ) ;
if ( V_80 < 0 )
F_19 ( - 1 , L_60 , V_79 ) ;
V_78 = F_30 ( V_80 , V_77 , sizeof( * V_77 ) , V_76 ) ;
if ( V_78 != sizeof( * V_77 ) )
F_19 ( - 1 , L_61 , V_79 , ( unsigned long long ) V_76 ) ;
if ( V_6 > 1 )
fprintf ( V_1 , L_62 , V_48 , V_76 , * V_77 ) ;
F_31 ( V_80 ) ;
return 0 ;
}
int F_32 ( int V_48 , int V_76 , unsigned long long V_82 )
{
char V_79 [ 32 ] ;
int V_78 ;
int V_80 ;
sprintf ( V_79 , L_59 , V_48 ) ;
V_80 = F_29 ( V_79 , V_83 ) ;
if ( V_80 < 0 )
F_19 ( - 1 , L_60 , V_79 ) ;
V_78 = F_33 ( V_80 , & V_82 , sizeof( V_82 ) , V_76 ) ;
if ( V_78 != sizeof( V_82 ) )
F_19 ( - 2 , L_63 , V_48 , V_76 , V_82 , V_78 ) ;
F_31 ( V_80 ) ;
if ( V_6 > 1 )
fprintf ( V_1 , L_64 , V_48 , V_76 , V_82 ) ;
return 0 ;
}
void F_34 ( int V_48 , struct V_84 * V_85 , char * V_86 )
{
if ( V_48 != - 1 )
printf ( L_65 , V_48 ) ;
printf ( L_66 ,
V_85 -> V_87 , V_85 -> V_88 , V_85 -> V_89 , V_85 -> V_90 ) ;
}
void F_35 ( int V_48 , struct V_84 * V_85 , unsigned int V_91 )
{
unsigned long long V_77 ;
F_28 ( V_48 , V_91 , & V_77 ) ;
V_85 -> V_90 = F_3 ( F_36 ( V_77 ) ) ;
V_85 -> V_89 = F_3 ( F_37 ( V_77 ) ) ;
V_85 -> V_88 = F_3 ( F_38 ( V_77 ) ) ;
V_85 -> V_87 = F_3 ( F_39 ( V_77 ) ) ;
}
void F_40 ( int V_48 , struct V_92 * V_93 , char * V_86 )
{
if ( V_48 != - 1 )
printf ( L_65 , V_48 ) ;
if ( V_86 )
printf ( L_25 , V_86 ) ;
printf ( L_67 ,
V_93 -> V_41 , V_93 -> V_42 , V_93 -> V_46 , V_93 -> V_43 ,
V_93 -> V_47 , V_93 -> V_47 & 0x7F , ( V_93 -> V_47 >> 7 ) & 0x7 , V_93 -> V_74 ) ;
}
void F_41 ( int V_57 , struct V_92 * V_93 , char * V_86 )
{
printf ( L_68 , V_57 ) ;
if ( V_86 )
printf ( L_25 , V_86 ) ;
printf ( L_69 ,
V_93 -> V_41 , V_93 -> V_42 , V_93 -> V_46 , V_93 -> V_43 ,
V_93 -> V_47 , V_93 -> V_47 & 0x7F , ( V_93 -> V_47 >> 7 ) & 0x7 ) ;
}
void F_42 ( int V_48 , struct V_92 * V_94 , unsigned int V_91 )
{
unsigned long long V_77 ;
F_28 ( V_48 , V_91 , & V_77 ) ;
V_94 -> V_41 = F_3 ( ( ( ( V_77 ) >> 0 ) & 0xff ) ) ;
V_94 -> V_42 = F_3 ( ( ( ( V_77 ) >> 8 ) & 0xff ) ) ;
V_94 -> V_46 = F_3 ( ( ( ( V_77 ) >> 16 ) & 0xff ) ) ;
V_94 -> V_43 = ( ( ( V_77 ) >> 24 ) & 0xff ) ;
V_94 -> V_47 = ( ( ( V_77 ) >> 32 ) & 0x3ff ) ;
V_94 -> V_74 = ( ( ( V_77 ) >> 42 ) & 0x1 ) ;
}
void F_43 ( int V_48 , struct V_92 * V_94 , unsigned int V_91 )
{
unsigned long long V_77 = 0 ;
if ( V_6 > 1 )
printf ( L_70 ,
V_48 , V_94 -> V_41 , V_94 -> V_42 ,
V_94 -> V_46 , V_94 -> V_43 ,
V_94 -> V_47 , V_94 -> V_74 ) ;
V_77 |= F_44 ( F_2 ( V_94 -> V_41 ) ) ;
V_77 |= F_45 ( F_2 ( V_94 -> V_42 ) ) ;
V_77 |= F_46 ( F_2 ( V_94 -> V_46 ) ) ;
V_77 |= F_47 ( V_94 -> V_43 ) ;
V_77 |= F_48 ( V_94 -> V_47 ) ;
V_77 |= F_49 ( V_94 -> V_74 ) ;
F_32 ( V_48 , V_91 , V_77 ) ;
}
int F_50 ( int V_48 )
{
unsigned long long V_77 ;
struct V_92 V_95 ;
struct V_84 V_85 ;
if ( V_9 ) {
F_28 ( V_48 , V_96 , & V_77 ) ;
printf ( L_71 , V_48 , ( unsigned int ) V_77 ) ;
}
if ( ! V_97 )
return 0 ;
F_42 ( V_48 , & V_95 , V_98 ) ;
F_40 ( V_48 , & V_95 , L_72 ) ;
F_35 ( V_48 , & V_85 , V_99 ) ;
F_34 ( V_48 , & V_85 , L_72 ) ;
return 0 ;
}
int F_51 ( int V_57 )
{
struct V_92 V_95 ;
unsigned long long V_77 ;
if ( ! V_97 )
return 0 ;
F_42 ( V_100 [ V_57 ] , & V_95 , V_101 ) ;
F_41 ( V_57 , & V_95 , L_72 ) ;
if ( V_102 ) {
F_28 ( V_100 [ V_57 ] , V_103 , & V_77 ) ;
fprintf ( V_1 ,
L_73 ,
V_57 , V_77 ,
( ( V_77 ) & 0x2 ) ? L_74 : L_75 ,
( ( V_77 ) & 0x1 ) ? L_74 : L_75 ) ;
}
F_28 ( V_100 [ V_57 ] , V_104 , & V_77 ) ;
fprintf ( V_1 ,
L_76 ,
V_57 , V_77 ,
( ( V_77 ) & 0x4 ) ? L_72 : L_77 ,
( ( V_77 ) & 0x1 ) ? L_72 : L_77 ) ;
return 0 ;
}
int F_52 ( int V_3 )
{
int V_105 = 100 * 1000 ;
return V_3 * V_105 ;
}
void F_53 ( int V_106 , int V_48 , unsigned int V_3 )
{
char V_79 [ 64 ] ;
T_1 * V_107 ;
int V_78 ;
int V_108 ;
sprintf ( V_79 , L_78 ,
V_48 , V_106 ? L_79 : L_80 ) ;
V_107 = fopen ( V_79 , L_81 ) ;
if ( ! V_107 ) {
if ( V_6 )
perror ( V_79 ) ;
return;
}
V_108 = F_52 ( V_3 ) ;
V_78 = fprintf ( V_107 , L_82 , V_108 ) ;
if ( V_78 < 0 )
if ( V_6 )
perror ( L_83 ) ;
if ( V_6 )
printf ( L_84 , V_108 , V_79 ) ;
fclose ( V_107 ) ;
}
int F_54 ( int V_48 )
{
if ( ! V_97 )
return 0 ;
if ( ! F_55 () )
return 0 ;
if ( F_56 ( L_85 , V_109 ) )
return 0 ;
if ( V_21 )
F_53 ( 0 , V_48 , V_40 . V_41 ) ;
if ( V_24 )
F_53 ( 1 , V_48 , V_40 . V_42 ) ;
return 0 ;
}
int F_57 ( int V_48 , struct V_92 * V_95 )
{
if ( V_95 -> V_41 > V_95 -> V_42 ) {
F_5 ( 1 , L_86 ,
V_48 , V_95 -> V_41 , V_95 -> V_42 ) ;
}
if ( V_95 -> V_46 && ( V_95 -> V_46 > V_95 -> V_42 ) ) {
F_5 ( 1 , L_87 ,
V_48 , V_95 -> V_46 , V_95 -> V_42 ) ;
}
if ( V_95 -> V_46 && ( V_95 -> V_46 < V_95 -> V_41 ) ) {
F_5 ( 1 , L_88 ,
V_48 , V_95 -> V_46 , V_95 -> V_41 ) ;
}
return 0 ;
}
int F_58 ( int V_48 , struct V_92 * V_95 , struct V_84 * V_85 )
{
if ( V_24 ) {
if ( V_95 -> V_42 > V_85 -> V_90 )
F_5 ( 1 , L_89 ,
V_48 , V_95 -> V_42 , V_85 -> V_90 ) ;
if ( V_95 -> V_42 < V_85 -> V_87 )
F_5 ( 1 , L_90 ,
V_48 , V_95 -> V_42 , V_85 -> V_87 ) ;
}
if ( V_21 ) {
if ( V_95 -> V_41 > V_85 -> V_90 )
F_5 ( 1 , L_91 ,
V_48 , V_95 -> V_41 , V_85 -> V_90 ) ;
if ( V_95 -> V_41 < V_85 -> V_87 )
F_5 ( 1 , L_92 ,
V_48 , V_95 -> V_41 , V_85 -> V_87 ) ;
}
if ( V_21 && V_24 && ( V_95 -> V_41 > V_95 -> V_42 ) )
F_5 ( 1 , L_93 ,
V_48 , V_95 -> V_41 , V_95 -> V_42 ) ;
if ( V_25 && V_95 -> V_46 ) {
if ( V_95 -> V_46 > V_95 -> V_42 )
F_5 ( 1 , L_94 ,
V_48 , V_95 -> V_46 , V_95 -> V_42 ) ;
if ( V_95 -> V_46 < V_95 -> V_41 )
F_5 ( 1 , L_95 ,
V_48 , V_95 -> V_46 , V_95 -> V_41 ) ;
if ( V_95 -> V_46 < V_85 -> V_87 )
F_5 ( 1 , L_96 ,
V_48 , V_95 -> V_46 , V_85 -> V_87 ) ;
if ( V_95 -> V_46 > V_85 -> V_90 )
F_5 ( 1 , L_97 ,
V_48 , V_95 -> V_46 , V_85 -> V_90 ) ;
}
return 0 ;
}
int F_59 ( int V_48 )
{
struct V_92 V_95 ;
struct V_84 V_85 ;
int V_91 = V_98 ;
F_42 ( V_48 , & V_95 , V_91 ) ;
if ( V_6 )
F_40 ( V_48 , & V_95 , L_98 ) ;
if ( V_21 )
V_95 . V_41 = V_40 . V_41 ;
if ( V_24 )
V_95 . V_42 = V_40 . V_42 ;
if ( V_25 )
V_95 . V_46 = V_40 . V_46 ;
if ( V_27 )
V_95 . V_47 = V_40 . V_47 ;
if ( V_28 )
V_95 . V_43 = V_40 . V_43 ;
V_95 . V_74 = V_40 . V_74 ;
F_35 ( V_48 , & V_85 , V_99 ) ;
if ( V_6 )
F_34 ( V_48 , & V_85 , L_72 ) ;
if ( ! V_38 )
F_58 ( V_48 , & V_95 , & V_85 ) ;
F_57 ( V_48 , & V_95 ) ;
F_43 ( V_48 , & V_95 , V_91 ) ;
if ( V_6 ) {
F_42 ( V_48 , & V_95 , V_91 ) ;
F_40 ( V_48 , & V_95 , L_99 ) ;
}
return 0 ;
}
int F_60 ( int V_57 )
{
struct V_92 V_95 ;
struct V_84 V_85 ;
int V_48 = V_100 [ V_57 ] ;
int V_91 = V_101 ;
F_42 ( V_48 , & V_95 , V_91 ) ;
if ( V_6 )
F_41 ( V_57 , & V_95 , L_98 ) ;
if ( V_21 )
V_95 . V_41 = V_40 . V_41 ;
if ( V_24 )
V_95 . V_42 = V_40 . V_42 ;
if ( V_25 )
V_95 . V_46 = V_40 . V_46 ;
if ( V_27 )
V_95 . V_47 = V_40 . V_47 ;
if ( V_28 )
V_95 . V_43 = V_40 . V_43 ;
F_35 ( V_48 , & V_85 , V_99 ) ;
if ( V_6 )
F_34 ( V_48 , & V_85 , L_72 ) ;
if ( ! V_38 )
F_58 ( V_48 , & V_95 , & V_85 ) ;
F_57 ( V_48 , & V_95 ) ;
F_43 ( V_48 , & V_95 , V_91 ) ;
if ( V_6 ) {
F_42 ( V_48 , & V_95 , V_91 ) ;
F_41 ( V_57 , & V_95 , L_99 ) ;
}
return 0 ;
}
int F_61 ( int V_48 )
{
unsigned long long V_77 ;
F_28 ( V_48 , V_110 , & V_77 ) ;
F_32 ( V_48 , V_110 , 1 ) ;
if ( V_72 )
printf ( L_100 , V_48 , ( unsigned int ) V_77 , 1 ) ;
return 0 ;
}
int F_62 ( int V_48 )
{
unsigned long long V_77 ;
if ( V_10 ) {
F_28 ( V_48 , V_96 , & V_77 ) ;
F_32 ( V_48 , V_96 , V_44 ) ;
if ( V_72 )
printf ( L_101 ,
V_48 , ( unsigned int ) V_77 , ( unsigned int ) V_44 ) ;
}
if ( V_33 ) {
int V_111 ;
F_28 ( V_48 , V_112 , & V_77 ) ;
V_111 = ( ( V_77 & V_113 ) != 0 ) ;
if ( V_45 == 1 ) {
if ( V_111 ) {
V_77 &= ~ V_113 ;
F_32 ( V_48 , V_112 , V_77 ) ;
if ( V_72 )
printf ( L_102 , V_48 ) ;
}
} else {
V_77 |= V_113 ;
F_32 ( V_48 , V_112 , V_77 ) ;
if ( V_72 )
printf ( L_103 , V_48 ) ;
}
}
if ( ! V_97 )
return 0 ;
if ( ! F_55 () )
return 0 ;
F_59 ( V_48 ) ;
return 0 ;
}
T_1 * F_63 ( const char * V_114 , const char * V_115 )
{
T_1 * V_116 = fopen ( V_114 , L_104 ) ;
if ( ! V_116 )
F_19 ( 1 , L_105 , V_114 ) ;
return V_116 ;
}
unsigned int F_64 ( int V_48 )
{
T_1 * V_107 ;
char V_79 [ 128 ] ;
unsigned int V_57 ;
int V_78 ;
sprintf ( V_79 , L_106 , V_48 ) ;
V_107 = F_63 ( V_79 , L_104 ) ;
V_78 = fscanf ( V_107 , L_107 , & V_57 ) ;
if ( V_78 != 1 )
F_5 ( 1 , L_108 , V_79 ) ;
return V_57 ;
}
int F_65 ( int V_48 )
{
unsigned int V_57 ;
if ( V_51 < V_48 )
V_51 = V_48 ;
V_57 = F_64 ( V_48 ) ;
if ( V_57 >= V_117 )
F_5 ( 1 , L_109 , V_48 , V_57 , V_117 ) ;
if ( V_57 > V_59 )
V_59 = V_57 ;
if ( ( V_60 & ( 1ULL << V_57 ) ) == 0 ) {
V_60 |= ( 1ULL << V_57 ) ;
V_100 [ V_57 ] = V_48 ;
}
return 0 ;
}
int F_66 ( int V_48 )
{
F_21 ( V_48 , V_49 , V_52 ) ;
return 0 ;
}
int F_67 ( int (F_24)( int ) )
{
T_1 * V_107 ;
int V_118 ;
int V_78 ;
V_107 = F_63 ( V_119 , L_104 ) ;
V_78 = fscanf ( V_107 , L_110 ) ;
if ( V_78 != 0 )
F_19 ( 1 , L_111 , V_119 ) ;
while ( 1 ) {
V_78 = fscanf ( V_107 , L_112 , & V_118 ) ;
if ( V_78 != 1 )
break;
V_78 = F_24 ( V_118 ) ;
if ( V_78 ) {
fclose ( V_107 ) ;
return V_78 ;
}
}
fclose ( V_107 ) ;
return 0 ;
}
void F_68 ( T_2 V_120 , T_3 * V_121 , int (F_24)( int ) )
{
int V_118 ;
for ( V_118 = 0 ; V_118 <= V_51 ; ++ V_118 )
if ( F_16 ( V_118 , V_120 , V_121 ) )
F_24 ( V_118 ) ;
}
void F_69 ( void )
{
F_67 ( F_65 ) ;
V_49 = F_70 ( ( V_51 + 1 ) ) ;
V_52 = F_18 ( ( V_51 + 1 ) ) ;
if ( V_52 == NULL )
F_19 ( 3 , L_113 ) ;
F_20 ( V_49 , V_52 ) ;
F_67 ( F_66 ) ;
}
void F_71 ( void )
{
unsigned long long V_77 ;
if ( ! V_97 )
return;
F_28 ( V_122 , V_110 , & V_77 ) ;
if ( ( V_77 & 1 ) == 0 ) {
fprintf ( V_1 , L_114 ) ;
V_97 = 0 ;
return;
}
}
int F_72 ( void )
{
if ( ! F_55 () )
return 0 ;
if ( ( V_24 && V_21 ) &&
( V_40 . V_41 > V_40 . V_42 ) ) {
printf ( L_115 , V_40 . V_41 , V_40 . V_42 ) ;
return - V_123 ;
}
if ( V_40 . V_46 && V_24 &&
( V_40 . V_46 > V_40 . V_42 ) ) {
printf ( L_116 ) ;
return - V_123 ;
}
if ( V_40 . V_46 && V_21 &&
( V_40 . V_46 < V_40 . V_41 ) ) {
printf ( L_117 ) ;
return - V_123 ;
}
return 0 ;
}
void F_73 ( void )
{
V_122 = F_74 () ;
if ( V_122 < 0 )
F_19 ( - V_124 , L_118 ) ;
}
void F_75 ( void )
{
struct V_125 V_126 ;
char V_79 [ 32 ] ;
sprintf ( V_79 , L_59 , V_122 ) ;
if ( V_125 ( V_79 , & V_126 ) )
if ( system ( L_119 ) )
F_19 ( - 5 , L_120 ) ;
}
void F_76 ( void )
{
unsigned int V_127 , V_128 , V_129 , V_130 , V_131 ;
unsigned int V_132 , V_133 , V_134 ;
F_77 ( 0 , & V_131 , & V_128 , & V_129 , & V_130 ) ;
if ( V_131 < 6 )
F_5 ( 1 , L_121 ) ;
F_77 ( 1 , & V_132 , & V_128 , & V_129 , & V_130 ) ;
V_133 = ( V_132 >> 8 ) & 0xf ;
V_134 = ( V_132 >> 4 ) & 0xf ;
if ( V_133 == 6 || V_133 == 0xf )
V_134 += ( ( V_132 >> 16 ) & 0xf ) << 4 ;
if ( V_134 == 0x4F ) {
unsigned long long V_77 ;
F_28 ( V_122 , V_135 , & V_77 ) ;
V_5 = V_77 & 0xFF ;
}
F_77 ( 0x6 , & V_127 , & V_128 , & V_129 , & V_130 ) ;
V_136 = ( V_127 >> 1 ) & 1 ;
V_97 = ( V_127 >> 7 ) & 1 ;
V_9 = ( V_129 >> 3 ) & 1 ;
}
void F_78 ( void )
{
unsigned int V_127 , V_128 , V_129 , V_130 , V_131 ;
unsigned int V_132 , V_133 , V_134 , V_137 ;
V_127 = V_128 = V_129 = V_130 = 0 ;
F_77 ( 0 , & V_131 , & V_128 , & V_129 , & V_130 ) ;
if ( V_128 == 0x756e6547 && V_130 == 0x49656e69 && V_129 == 0x6c65746e )
V_138 = 1 ;
if ( V_6 )
fprintf ( V_1 , L_122 ,
( char * ) & V_128 , ( char * ) & V_130 , ( char * ) & V_129 ) ;
F_77 ( 1 , & V_132 , & V_128 , & V_129 , & V_130 ) ;
V_133 = ( V_132 >> 8 ) & 0xf ;
V_134 = ( V_132 >> 4 ) & 0xf ;
V_137 = V_132 & 0xf ;
if ( V_133 == 6 || V_133 == 0xf )
V_134 += ( ( V_132 >> 16 ) & 0xf ) << 4 ;
if ( V_6 ) {
fprintf ( V_1 , L_123 ,
V_131 , V_133 , V_134 , V_137 , V_133 , V_134 , V_137 ) ;
fprintf ( V_1 , L_124 ,
V_129 & ( 1 << 0 ) ? L_125 : L_126 ,
V_129 & ( 1 << 3 ) ? L_127 : L_126 ,
V_129 & ( 1 << 7 ) ? L_128 : L_126 ,
V_129 & ( 1 << 8 ) ? L_129 : L_126 ,
V_130 & ( 1 << 4 ) ? L_130 : L_126 ,
V_130 & ( 1 << 5 ) ? L_131 : L_126 ,
V_130 & ( 1 << 22 ) ? L_132 : L_126 ,
V_130 & ( 1 << 29 ) ? L_133 : L_126 ) ;
}
if ( ! ( V_130 & ( 1 << 5 ) ) )
F_5 ( 1 , L_134 ) ;
F_77 ( 0x6 , & V_127 , & V_128 , & V_129 , & V_130 ) ;
V_102 = V_127 & ( 1 << 8 ) ;
V_139 = V_127 & ( 1 << 9 ) ;
V_140 = V_127 & ( 1 << 10 ) ;
V_141 = V_127 & ( 1 << 11 ) ;
if ( ! V_141 && V_73 )
F_5 ( 1 , L_135 ) ;
if ( V_6 )
fprintf ( V_1 ,
L_136 ,
V_136 ? L_72 : L_77 ,
V_97 ? L_72 : L_77 ,
V_102 ? L_72 : L_77 ,
V_139 ? L_72 : L_77 ,
V_140 ? L_72 : L_77 ,
V_141 ? L_72 : L_77 ,
V_9 ? L_72 : L_77 ) ;
return;
}
int main ( int V_63 , char * * V_64 )
{
F_73 () ;
F_75 () ;
F_69 () ;
F_76 () ;
F_26 ( V_63 , V_64 ) ;
if ( V_6 )
F_25 () ;
F_78 () ;
if ( ( V_50 == 0 ) && ( V_55 == 0 ) )
V_50 = V_52 ;
if ( V_39 )
F_68 ( V_49 , V_50 , F_61 ) ;
F_71 () ;
if ( F_72 () )
return - V_123 ;
if ( ! V_10 && ! V_33 && ! F_55 () ) {
if ( V_50 )
F_68 ( V_49 , V_50 , F_50 ) ;
if ( V_141 ) {
if ( V_55 == 0 )
V_55 = V_60 ;
F_23 ( V_55 , F_51 ) ;
}
return 0 ;
}
if ( V_50 ) {
F_68 ( V_49 , V_50 , F_54 ) ;
F_68 ( V_49 , V_50 , F_62 ) ;
} else if ( V_55 )
F_23 ( V_55 , F_60 ) ;
return 0 ;
}
