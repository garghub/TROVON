int F_1 ( int V_1 , int V_2 , int V_3 )
{
F_2 ( V_3 , V_4 , V_5 ) ;
return 0 ;
}
void F_3 ( int V_6 )
{
V_7 = F_4 ( V_6 ) ;
if ( V_7 == NULL ) {
perror ( L_1 ) ;
exit ( 3 ) ;
}
V_8 = F_5 ( V_6 ) ;
F_6 ( V_8 , V_7 ) ;
V_5 = F_4 ( V_6 ) ;
if ( V_5 == NULL ) {
perror ( L_1 ) ;
exit ( 3 ) ;
}
V_4 = F_5 ( V_6 ) ;
F_6 ( V_4 , V_5 ) ;
F_7 ( F_1 ) ;
}
void F_8 ()
{
F_9 ( V_7 ) ;
V_7 = NULL ;
V_8 = 0 ;
F_9 ( V_5 ) ;
V_5 = NULL ;
V_4 = 0 ;
}
int F_10 ( int V_3 )
{
F_6 ( V_8 , V_7 ) ;
F_2 ( V_3 , V_8 , V_7 ) ;
if ( F_11 ( 0 , V_8 , V_7 ) == - 1 )
return - 1 ;
else
return 0 ;
}
int F_12 ( int V_3 , T_1 V_9 , unsigned long long * V_10 )
{
T_2 V_11 ;
char V_12 [ 32 ] ;
int V_13 ;
sprintf ( V_12 , L_2 , V_3 ) ;
V_13 = F_13 ( V_12 , V_14 ) ;
if ( V_13 < 0 )
return - 1 ;
V_11 = F_14 ( V_13 , V_10 , sizeof *V_10 , V_9 ) ;
F_15 ( V_13 ) ;
if ( V_11 != sizeof *V_10 )
return - 1 ;
return 0 ;
}
void F_16 ( void )
{
if ( V_15 )
fprintf ( V_16 , L_3 ) ;
if ( V_15 )
fprintf ( V_16 , L_4 ) ;
if ( V_17 )
fprintf ( V_16 , L_5 ) ;
if ( V_18 )
fprintf ( V_16 , L_6 ) ;
if ( V_15 || V_17 || V_18 )
fprintf ( V_16 , L_4 ) ;
if ( V_19 )
fprintf ( V_16 , L_7 ) ;
if ( V_20 )
fprintf ( V_16 , L_8 ) ;
fprintf ( V_16 , L_9 ) ;
if ( V_19 )
fprintf ( V_16 , L_10 ) ;
if ( V_19 )
fprintf ( V_16 , L_11 ) ;
if ( V_19 )
fprintf ( V_16 , L_12 ) ;
if ( V_21 )
fprintf ( V_16 , L_13 ) ;
if ( V_21 )
fprintf ( V_16 , L_14 ) ;
if ( V_19 )
fprintf ( V_16 , L_15 ) ;
if ( V_19 )
fprintf ( V_16 , L_16 ) ;
if ( V_21 )
fprintf ( V_16 , L_17 ) ;
if ( V_22 )
fprintf ( V_16 , L_18 , V_22 ) ;
putc ( '\n' , V_16 ) ;
}
void F_17 ( struct V_23 * V_24 )
{
if ( ! V_24 )
return;
if ( V_24 -> V_1 ) fprintf ( V_16 , L_19 , V_24 -> V_1 ) ;
if ( V_24 -> V_2 ) fprintf ( V_16 , L_20 , V_24 -> V_2 ) ;
if ( V_24 -> V_3 ) fprintf ( V_16 , L_21 , V_24 -> V_3 ) ;
if ( V_24 -> V_25 ) fprintf ( V_16 , L_22 , V_24 -> V_25 ) ;
if ( V_24 -> V_26 ) fprintf ( V_16 , L_23 , V_24 -> V_26 ) ;
if ( V_24 -> V_27 ) fprintf ( V_16 , L_24 , V_24 -> V_27 ) ;
if ( V_24 -> V_28 ) fprintf ( V_16 , L_25 , V_24 -> V_28 ) ;
if ( V_24 -> V_29 ) fprintf ( V_16 , L_26 , V_24 -> V_29 ) ;
if ( V_24 -> V_30 ) fprintf ( V_16 , L_27 , V_24 -> V_30 ) ;
if ( V_24 -> V_31 ) fprintf ( V_16 , L_28 , V_24 -> V_31 ) ;
if ( V_24 -> V_32 ) fprintf ( V_16 , L_29 , V_24 -> V_32 ) ;
if ( V_24 -> V_33 ) fprintf ( V_16 , L_30 , V_24 -> V_33 ) ;
if ( V_24 -> V_34 ) fprintf ( V_16 , L_31 , V_22 , V_24 -> V_34 ) ;
}
void F_18 ( struct V_23 * V_24 )
{
printf ( L_32 , V_24 ) ;
for (; V_24 ; V_24 = V_24 -> V_35 )
F_17 ( V_24 ) ;
}
void F_19 ( struct V_23 * V_36 )
{
double V_37 ;
V_37 = V_38 . V_39 + V_38 . V_40 / 1000000.0 ;
if ( V_36 == V_41 ) {
if ( V_15 )
fprintf ( V_16 , L_33 ) ;
if ( V_15 && V_17 )
fprintf ( V_16 , L_4 ) ;
if ( V_17 )
fprintf ( V_16 , L_34 ) ;
if ( V_18 )
fprintf ( V_16 , L_4 L_34 ) ;
} else {
if ( V_15 )
fprintf ( V_16 , L_35 , V_36 -> V_1 ) ;
if ( V_15 && V_17 )
fprintf ( V_16 , L_4 ) ;
if ( V_17 )
fprintf ( V_16 , L_36 , V_36 -> V_2 ) ;
if ( V_18 )
fprintf ( V_16 , L_37 , V_36 -> V_3 ) ;
}
if ( V_19 ) {
if ( V_15 || V_17 || V_18 )
fprintf ( V_16 , L_4 ) ;
if ( ! V_42 )
fprintf ( V_16 , L_38 , 100.0 * V_36 -> V_43 / V_36 -> V_25 ) ;
else
fprintf ( V_16 , L_39 ) ;
}
if ( V_20 ) {
if ( ! V_44 ) {
fprintf ( V_16 , L_40 ,
1.0 * V_36 -> V_25 / V_45 * V_36 -> V_29 /
V_36 -> V_43 / V_37 ) ;
} else {
if ( V_36 -> V_29 > V_36 -> V_25 || V_36 -> V_43 > V_36 -> V_25 ) {
fprintf ( V_16 , L_41 ) ;
} else {
fprintf ( V_16 , L_42 ,
1.0 * V_36 -> V_25 /
V_45 * V_36 -> V_29 /
V_36 -> V_43 / V_37 ) ;
}
}
}
fprintf ( V_16 , L_43 , 1.0 * V_36 -> V_25 / V_45 / V_37 ) ;
if ( V_19 ) {
if ( ! V_46 )
fprintf ( V_16 , L_44 , 100.0 * V_36 -> V_47 / V_36 -> V_25 ) ;
else
fprintf ( V_16 , L_39 ) ;
}
if ( V_19 )
fprintf ( V_16 , L_44 , 100.0 * V_36 -> V_26 / V_36 -> V_25 ) ;
if ( V_19 )
fprintf ( V_16 , L_44 , 100.0 * V_36 -> V_27 / V_36 -> V_25 ) ;
if ( V_21 )
fprintf ( V_16 , L_44 , 100.0 * V_36 -> V_28 / V_36 -> V_25 ) ;
if ( V_21 )
fprintf ( V_16 , L_44 , 100.0 * V_36 -> V_30 / V_36 -> V_25 ) ;
if ( V_19 )
fprintf ( V_16 , L_44 , 100.0 * V_36 -> V_31 / V_36 -> V_25 ) ;
if ( V_19 )
fprintf ( V_16 , L_44 , 100.0 * V_36 -> V_32 / V_36 -> V_25 ) ;
if ( V_21 )
fprintf ( V_16 , L_44 , 100.0 * V_36 -> V_33 / V_36 -> V_25 ) ;
if ( V_22 )
fprintf ( V_16 , L_45 , V_36 -> V_34 ) ;
putc ( '\n' , V_16 ) ;
}
void F_20 ( struct V_23 * V_23 )
{
struct V_23 * V_24 ;
static int V_48 ;
if ( ! V_48 || ! V_49 )
F_16 () ;
if ( V_50 > 1 )
F_19 ( V_41 ) ;
V_48 = 1 ;
if ( V_49 )
return;
for ( V_24 = V_23 ; V_24 != NULL ; V_24 = V_24 -> V_35 )
F_19 ( V_24 ) ;
}
int F_21 ( struct V_23 * V_51 ,
struct V_23 * V_52 , struct V_23 * V_53 )
{
int V_54 = 0 ;
int V_55 = 0 ;
V_42 = V_46 = 0 ;
for ( ; V_51 && V_52 && V_53 ;
V_51 = V_51 -> V_35 , V_52 = V_52 -> V_35 , V_53 = V_53 -> V_35 ) {
if ( V_52 -> V_3 != V_51 -> V_3 ) {
printf ( L_46 ,
V_52 -> V_3 , V_51 -> V_3 ) ;
return - 1 ;
}
if ( F_22 ( V_51 -> V_25 , V_52 -> V_25 , V_53 -> V_25 ) ) {
fprintf ( V_16 , L_47 ,
V_52 -> V_3 , V_52 -> V_25 , V_51 -> V_25 ) ;
V_54 ++ ;
}
if ( V_53 -> V_25 < ( 1000 * 1000 ) ) {
fprintf ( V_16 , L_48
L_49 ) ;
fprintf ( V_16 , L_50
L_51 ) ;
fprintf ( V_16 , L_52
L_53 ) ;
exit ( - 3 ) ;
}
if ( F_22 ( V_51 -> V_26 , V_52 -> V_26 , V_53 -> V_26 ) ) {
fprintf ( V_16 , L_54 ,
V_52 -> V_3 , V_52 -> V_26 , V_51 -> V_26 ) ;
V_54 ++ ;
}
if ( F_22 ( V_51 -> V_27 , V_52 -> V_27 , V_53 -> V_27 ) ) {
fprintf ( V_16 , L_55 ,
V_52 -> V_3 , V_52 -> V_27 , V_51 -> V_27 ) ;
V_54 ++ ;
}
if ( F_22 ( V_51 -> V_28 , V_52 -> V_28 , V_53 -> V_28 ) ) {
fprintf ( V_16 , L_56 ,
V_52 -> V_3 , V_52 -> V_28 , V_51 -> V_28 ) ;
V_54 ++ ;
}
if ( F_22 ( V_51 -> V_30 , V_52 -> V_30 , V_53 -> V_30 ) ) {
fprintf ( V_16 , L_57 ,
V_52 -> V_3 , V_52 -> V_30 , V_51 -> V_30 ) ;
V_54 ++ ;
}
if ( F_22 ( V_51 -> V_31 , V_52 -> V_31 , V_53 -> V_31 ) ) {
fprintf ( V_16 , L_58 ,
V_52 -> V_3 , V_52 -> V_31 , V_51 -> V_31 ) ;
V_54 ++ ;
}
if ( F_22 ( V_51 -> V_32 , V_52 -> V_32 , V_53 -> V_32 ) ) {
fprintf ( V_16 , L_59 ,
V_52 -> V_3 , V_52 -> V_32 , V_51 -> V_32 ) ;
V_54 ++ ;
}
if ( F_22 ( V_51 -> V_33 , V_52 -> V_33 , V_53 -> V_33 ) ) {
fprintf ( V_16 , L_60 ,
V_52 -> V_3 , V_52 -> V_33 , V_51 -> V_33 ) ;
V_54 ++ ;
}
V_55 = F_22 ( V_51 -> V_29 , V_52 -> V_29 , V_53 -> V_29 ) ;
if ( V_55 ) {
fprintf ( V_16 , L_61 ,
V_52 -> V_3 , V_52 -> V_29 , V_51 -> V_29 ) ;
}
V_55 |= F_22 ( V_51 -> V_43 , V_52 -> V_43 , V_53 -> V_43 ) ;
if ( V_55 ) {
fprintf ( V_16 , L_62 ,
V_52 -> V_3 , V_52 -> V_43 , V_51 -> V_43 ) ;
}
if ( V_55 ) {
if ( ! V_44 ) {
fprintf ( V_16 , L_63 , V_56 ) ;
fprintf ( V_16 , L_64 ) ;
fprintf ( V_16 , L_65 ) ;
V_44 = 1 ;
}
V_42 = 1 ;
V_46 = 1 ;
}
if ( V_53 -> V_43 > V_53 -> V_25 )
V_53 -> V_47 = 0 ;
else
V_53 -> V_47 = V_53 -> V_25 - V_53 -> V_43
- V_53 -> V_26 - V_53 -> V_27 - V_53 -> V_28 ;
if ( V_53 -> V_43 == 0 )
V_53 -> V_43 = 1 ;
V_53 -> V_34 = V_51 -> V_34 ;
if ( V_54 ) {
fprintf ( V_16 , L_66 , V_52 -> V_3 ) ;
F_17 ( V_52 ) ;
fprintf ( V_16 , L_67 , V_52 -> V_3 ) ;
F_17 ( V_51 ) ;
V_54 = 0 ;
}
}
return 0 ;
}
void F_23 ( struct V_23 * V_53 , struct V_23 * V_57 )
{
struct V_23 * V_58 ;
V_58 = calloc ( 1 , sizeof( struct V_23 ) ) ;
if ( V_58 == NULL ) {
perror ( L_68 ) ;
exit ( 1 ) ;
}
for (; V_53 ; V_53 = V_53 -> V_35 ) {
V_58 -> V_25 += V_53 -> V_25 ;
V_58 -> V_47 += V_53 -> V_47 ;
V_58 -> V_26 += V_53 -> V_26 ;
V_58 -> V_27 += V_53 -> V_27 ;
V_58 -> V_28 += V_53 -> V_28 ;
V_58 -> V_29 += V_53 -> V_29 ;
V_58 -> V_43 += V_53 -> V_43 ;
V_58 -> V_30 += V_53 -> V_30 ;
V_58 -> V_31 += V_53 -> V_31 ;
V_58 -> V_32 += V_53 -> V_32 ;
V_58 -> V_33 += V_53 -> V_33 ;
}
V_57 -> V_25 = V_58 -> V_25 / V_50 ;
V_57 -> V_47 = V_58 -> V_47 / V_50 ;
V_57 -> V_26 = V_58 -> V_26 / V_50 ;
V_57 -> V_27 = V_58 -> V_27 / V_50 ;
V_57 -> V_28 = V_58 -> V_28 / V_50 ;
V_57 -> V_29 = V_58 -> V_29 / V_50 ;
V_57 -> V_43 = V_58 -> V_43 / V_50 ;
V_57 -> V_30 = V_58 -> V_30 / V_50 ;
V_57 -> V_31 = V_58 -> V_31 / V_50 ;
V_57 -> V_32 = V_58 -> V_32 / V_50 ;
V_57 -> V_33 = V_58 -> V_33 / V_50 ;
free ( V_58 ) ;
}
int F_24 ( struct V_23 * V_24 )
{
for ( ; V_24 ; V_24 = V_24 -> V_35 ) {
if ( F_10 ( V_24 -> V_3 ) )
return - 1 ;
if ( F_12 ( V_24 -> V_3 , V_59 , & V_24 -> V_25 ) )
return - 1 ;
if ( V_20 ) {
if ( F_12 ( V_24 -> V_3 , V_60 , & V_24 -> V_29 ) )
return - 1 ;
if ( F_12 ( V_24 -> V_3 , V_61 , & V_24 -> V_43 ) )
return - 1 ;
}
if ( V_19 ) {
if ( F_12 ( V_24 -> V_3 , V_62 , & V_24 -> V_26 ) )
return - 1 ;
if ( F_12 ( V_24 -> V_3 , V_63 , & V_24 -> V_27 ) )
return - 1 ;
}
if ( V_21 )
if ( F_12 ( V_24 -> V_3 , V_64 , & V_24 -> V_28 ) )
return - 1 ;
if ( V_19 ) {
if ( F_12 ( V_24 -> V_3 , V_65 , & V_24 -> V_31 ) )
return - 1 ;
if ( F_12 ( V_24 -> V_3 , V_66 , & V_24 -> V_32 ) )
return - 1 ;
}
if ( V_21 ) {
if ( F_12 ( V_24 -> V_3 , V_67 , & V_24 -> V_30 ) )
return - 1 ;
if ( F_12 ( V_24 -> V_3 , V_68 , & V_24 -> V_33 ) )
return - 1 ;
}
if ( V_22 )
if ( F_12 ( V_24 -> V_3 , V_22 , & V_24 -> V_34 ) )
return - 1 ;
}
return 0 ;
}
void F_25 ( void )
{
unsigned long long V_10 ;
unsigned int V_69 ;
if ( ! V_70 )
return;
F_12 ( 0 , V_71 , & V_10 ) ;
V_69 = ( V_10 >> 40 ) & 0xFF ;
fprintf ( V_16 , L_69 ,
V_69 , V_72 , V_69 * V_72 ) ;
V_69 = ( V_10 >> 8 ) & 0xFF ;
fprintf ( V_16 , L_70 ,
V_69 , V_72 , V_69 * V_72 ) ;
if ( V_73 > 1 )
fprintf ( V_16 , L_71 , V_10 ) ;
if ( ! V_74 )
return;
F_12 ( 0 , V_75 , & V_10 ) ;
V_69 = ( V_10 >> 24 ) & 0xFF ;
if ( V_69 )
fprintf ( V_16 , L_72 ,
V_69 , V_72 , V_69 * V_72 ) ;
V_69 = ( V_10 >> 16 ) & 0xFF ;
if ( V_69 )
fprintf ( V_16 , L_73 ,
V_69 , V_72 , V_69 * V_72 ) ;
V_69 = ( V_10 >> 8 ) & 0xFF ;
if ( V_69 )
fprintf ( V_16 , L_74 ,
V_69 , V_72 , V_69 * V_72 ) ;
V_69 = ( V_10 >> 0 ) & 0xFF ;
if ( V_69 )
fprintf ( V_16 , L_75 ,
V_69 , V_72 , V_69 * V_72 ) ;
}
void F_26 ( struct V_23 * V_76 )
{
struct V_23 * V_36 ;
for ( V_36 = V_76 ; V_36 ; ) {
struct V_23 * V_77 ;
V_77 = V_36 ;
V_36 = V_36 -> V_35 ;
free ( V_77 ) ;
}
}
void F_27 ( void )
{
F_26 ( V_78 ) ;
V_78 = NULL ;
F_26 ( V_79 ) ;
V_79 = NULL ;
F_26 ( V_80 ) ;
V_80 = NULL ;
F_26 ( V_41 ) ;
V_41 = NULL ;
}
void F_28 ( struct V_23 * * V_76 ,
struct V_23 * V_81 )
{
struct V_23 * V_82 ;
if ( * V_76 == NULL ) {
V_81 -> V_35 = * V_76 ;
* V_76 = V_81 ;
return;
}
if ( ! V_49 )
V_18 = 1 ;
if ( ( ( * V_76 ) -> V_1 > V_81 -> V_1 ) ||
( ( ( * V_76 ) -> V_1 == V_81 -> V_1 ) && ( ( * V_76 ) -> V_2 > V_81 -> V_2 ) ) ||
( ( ( * V_76 ) -> V_1 == V_81 -> V_1 ) && ( ( * V_76 ) -> V_2 == V_81 -> V_2 ) && ( ( * V_76 ) -> V_3 > V_81 -> V_3 ) ) ) {
V_81 -> V_35 = * V_76 ;
* V_76 = V_81 ;
return;
}
V_82 = * V_76 ;
while ( V_82 -> V_35 && ( V_82 -> V_35 -> V_1 < V_81 -> V_1 ) ) {
V_82 = V_82 -> V_35 ;
if ( ! V_49 )
V_15 = 1 ;
}
while ( V_82 -> V_35 && ( V_82 -> V_35 -> V_1 == V_81 -> V_1 )
&& ( V_82 -> V_35 -> V_2 < V_81 -> V_2 ) ) {
V_82 = V_82 -> V_35 ;
if ( ! V_49 )
V_17 = 1 ;
}
while ( V_82 -> V_35 && ( V_82 -> V_35 -> V_1 == V_81 -> V_1 )
&& ( V_82 -> V_35 -> V_2 == V_81 -> V_2 )
&& ( V_82 -> V_35 -> V_3 < V_81 -> V_3 ) ) {
V_82 = V_82 -> V_35 ;
}
V_81 -> V_35 = V_82 -> V_35 ;
V_82 -> V_35 = V_81 ;
}
void F_29 ( int V_1 , int V_2 , int V_3 )
{
struct V_23 * V_81 ;
if ( V_73 > 1 )
printf ( L_76 , V_1 , V_2 , V_3 ) ;
V_81 = (struct V_23 * ) calloc ( 1 , sizeof( struct V_23 ) ) ;
if ( V_81 == NULL ) {
perror ( L_77 ) ;
exit ( 1 ) ;
}
V_81 -> V_1 = V_1 ;
V_81 -> V_2 = V_2 ;
V_81 -> V_3 = V_3 ;
F_28 ( & V_79 , V_81 ) ;
V_81 = (struct V_23 * ) calloc ( 1 ,
sizeof( struct V_23 ) ) ;
if ( V_81 == NULL ) {
perror ( L_77 ) ;
exit ( 1 ) ;
}
V_81 -> V_1 = V_1 ;
V_81 -> V_2 = V_2 ;
V_81 -> V_3 = V_3 ;
F_28 ( & V_78 , V_81 ) ;
V_81 = (struct V_23 * ) calloc ( 1 , sizeof( struct V_23 ) ) ;
if ( V_81 == NULL ) {
perror ( L_77 ) ;
exit ( 1 ) ;
}
V_81 -> V_1 = V_1 ;
V_81 -> V_2 = V_2 ;
V_81 -> V_3 = V_3 ;
F_28 ( & V_80 , V_81 ) ;
V_81 = (struct V_23 * ) calloc ( 1 , sizeof( struct V_23 ) ) ;
if ( V_81 == NULL ) {
perror ( L_77 ) ;
exit ( 1 ) ;
}
V_81 -> V_1 = V_1 ;
V_81 -> V_2 = V_2 ;
V_81 -> V_3 = V_3 ;
V_41 = V_81 ;
}
int F_30 ( int V_3 )
{
char V_83 [ 64 ] ;
T_3 * V_84 ;
int V_1 ;
sprintf ( V_83 , L_78 , V_3 ) ;
V_84 = fopen ( V_83 , L_79 ) ;
if ( V_84 == NULL ) {
perror ( V_83 ) ;
exit ( 1 ) ;
}
fscanf ( V_84 , L_80 , & V_1 ) ;
fclose ( V_84 ) ;
return V_1 ;
}
int F_31 ( int V_3 )
{
char V_83 [ 64 ] ;
T_3 * V_84 ;
int V_2 ;
sprintf ( V_83 , L_81 , V_3 ) ;
V_84 = fopen ( V_83 , L_79 ) ;
if ( V_84 == NULL ) {
perror ( V_83 ) ;
exit ( 1 ) ;
}
fscanf ( V_84 , L_80 , & V_2 ) ;
fclose ( V_84 ) ;
return V_2 ;
}
int F_7 ( void (F_32)( int , int , int ) )
{
T_3 * V_85 ;
int V_86 ;
int V_11 ;
V_85 = fopen ( V_87 , L_79 ) ;
if ( V_85 == NULL ) {
perror ( V_87 ) ;
exit ( 1 ) ;
}
V_11 = fscanf ( V_85 , L_82 ) ;
if ( V_11 != 0 ) {
perror ( L_83 ) ;
exit ( 1 ) ;
}
for ( V_86 = 0 ; ; V_86 ++ ) {
int V_3 ;
V_11 = fscanf ( V_85 , L_84 , & V_3 ) ;
if ( V_11 != 1 )
break;
F_32 ( F_30 ( V_3 ) , F_31 ( V_3 ) , V_3 ) ;
}
fclose ( V_85 ) ;
return V_86 ;
}
void F_33 ( void )
{
F_27 () ;
V_50 = F_7 ( F_29 ) ;
F_8 () ;
F_3 ( V_50 ) ;
printf ( L_85 , V_50 ) ;
}
void F_34 ( int V_1 , int V_2 , int V_3 ) { return; }
int F_35 ( void )
{
int V_88 ;
V_88 = F_7 ( F_34 ) ;
if ( V_88 != V_50 ) {
if ( V_73 )
printf ( L_86 ,
V_50 , V_88 ) ;
return - 1 ;
}
return 0 ;
}
void F_36 ()
{
V_89:
F_24 ( V_78 ) ;
F_37 ( & V_90 , (struct V_91 * ) NULL ) ;
while ( 1 ) {
if ( F_35 () ) {
F_33 () ;
goto V_89;
}
F_38 ( V_92 ) ;
if ( F_24 ( V_79 ) ) {
F_33 () ;
goto V_89;
}
F_37 ( & V_93 , (struct V_91 * ) NULL ) ;
F_21 ( V_79 , V_78 , V_80 ) ;
F_39 ( & V_93 , & V_90 , & V_38 ) ;
F_23 ( V_80 , V_41 ) ;
F_20 ( V_80 ) ;
F_38 ( V_92 ) ;
if ( F_24 ( V_78 ) ) {
F_33 () ;
goto V_89;
}
F_37 ( & V_90 , (struct V_91 * ) NULL ) ;
F_21 ( V_78 , V_79 , V_80 ) ;
F_39 ( & V_90 , & V_93 , & V_38 ) ;
F_23 ( V_80 , V_41 ) ;
F_20 ( V_80 ) ;
}
}
void F_40 ()
{
struct V_94 V_95 ;
if ( V_94 ( L_87 , & V_95 ) ) {
fprintf ( V_16 , L_88 ) ;
fprintf ( V_16 , L_89 ) ;
exit ( - 5 ) ;
}
}
void F_41 ()
{
if ( F_42 () != 0 ) {
fprintf ( V_16 , L_90 ) ;
exit ( - 6 ) ;
}
}
int F_43 ( unsigned int V_96 , unsigned int V_97 )
{
if ( ! V_98 )
return 0 ;
if ( V_96 != 6 )
return 0 ;
switch ( V_97 ) {
case 0x1A :
case 0x1E :
case 0x1F :
case 0x25 :
case 0x2C :
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3D :
return 1 ;
case 0x2E :
case 0x2F :
default:
return 0 ;
}
}
int F_44 ( unsigned int V_96 , unsigned int V_97 )
{
if ( ! V_98 )
return 0 ;
switch ( V_97 ) {
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3D :
return 1 ;
}
return 0 ;
}
double F_45 ( unsigned int V_96 , unsigned int V_97 )
{
if ( F_44 ( V_96 , V_97 ) )
return 100.00 ;
else
return 133.33 ;
}
void F_46 ()
{
unsigned int V_99 , V_100 , V_101 , V_102 , V_103 ;
unsigned int V_104 , V_96 , V_97 , V_105 ;
V_99 = V_100 = V_101 = V_102 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0));
if ( V_100 == 0x756e6547 && V_102 == 0x49656e69 && V_101 == 0x6c65746e )
V_98 = 1 ;
if ( V_73 )
fprintf ( V_16 , L_91 ,
( char * ) & V_100 , ( char * ) & V_102 , ( char * ) & V_101 ) ;
asm("cpuid" : "=a" (fms), "=c" (ecx), "=d" (edx) : "a" (1) : "ebx");
V_96 = ( V_104 >> 8 ) & 0xf ;
V_97 = ( V_104 >> 4 ) & 0xf ;
V_105 = V_104 & 0xf ;
if ( V_96 == 6 || V_96 == 0xf )
V_97 += ( ( V_104 >> 16 ) & 0xf ) << 4 ;
if ( V_73 )
fprintf ( V_16 , L_92 ,
V_103 , V_96 , V_97 , V_105 , V_96 , V_97 , V_105 ) ;
if ( ! ( V_102 & ( 1 << 5 ) ) ) {
fprintf ( V_16 , L_93 ) ;
exit ( 1 ) ;
}
V_100 = V_101 = V_102 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000000));
if ( V_103 < 0x80000007 ) {
fprintf ( V_16 , L_94 , V_103 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000007));
V_106 = V_102 & ( 1 << 8 ) ;
if ( ! V_106 ) {
fprintf ( V_16 , L_95 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x6));
V_20 = V_101 & ( 1 << 0 ) ;
if ( ! V_20 ) {
fprintf ( V_16 , L_96 ) ;
exit ( 1 ) ;
}
V_70 = V_98 && V_106 ;
V_19 = V_98 ;
V_21 = F_44 ( V_96 , V_97 ) ;
V_72 = F_45 ( V_96 , V_97 ) ;
V_74 = F_43 ( V_96 , V_97 ) ;
}
void F_47 ()
{
fprintf ( V_16 , L_97 ,
V_56 ) ;
exit ( 1 ) ;
}
int F_48 ( const struct V_107 * V_108 )
{
if ( isdigit ( V_108 -> V_109 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_49 ( int V_110 )
{
return 0 ;
}
void F_50 ()
{
F_46 () ;
F_40 () ;
F_41 () ;
V_50 = F_7 ( F_29 ) ;
F_3 ( V_50 ) ;
if ( V_73 )
F_25 () ;
}
int F_51 ( char * * V_111 )
{
int V_11 ;
T_4 V_112 ;
F_24 ( V_78 ) ;
F_11 ( 0 , V_4 , V_5 ) ;
F_37 ( & V_90 , (struct V_91 * ) NULL ) ;
V_112 = F_52 () ;
if ( ! V_112 ) {
F_53 ( V_111 [ 0 ] , V_111 ) ;
} else {
int V_113 ;
if ( V_112 == - 1 ) {
perror ( L_98 ) ;
exit ( 1 ) ;
}
signal ( V_114 , V_115 ) ;
signal ( V_116 , V_115 ) ;
if ( F_54 ( V_112 , & V_113 , 0 ) == - 1 ) {
perror ( L_99 ) ;
exit ( 1 ) ;
}
}
F_24 ( V_79 ) ;
F_37 ( & V_93 , (struct V_91 * ) NULL ) ;
V_11 = F_21 ( V_79 , V_78 , V_80 ) ;
F_39 ( & V_93 , & V_90 , & V_38 ) ;
F_23 ( V_80 , V_41 ) ;
if ( ! V_11 )
F_20 ( V_80 ) ;
fprintf ( V_16 , L_100 , V_38 . V_39 + V_38 . V_40 / 1000000.0 ) ;
return 0 ;
}
void F_55 ( int V_117 , char * * V_111 )
{
int V_118 ;
V_56 = V_111 [ 0 ] ;
while ( ( V_118 = F_56 ( V_117 , V_111 , L_101 ) ) != - 1 ) {
switch ( V_118 ) {
case 's' :
V_49 ++ ;
break;
case 'v' :
V_73 ++ ;
break;
case 'i' :
V_92 = atoi ( V_119 ) ;
break;
case 'M' :
sscanf ( V_119 , L_102 , & V_22 ) ;
if ( V_73 > 1 )
fprintf ( V_16 , L_103 , V_22 ) ;
break;
default:
F_47 () ;
}
}
}
int main ( int V_117 , char * * V_111 )
{
F_55 ( V_117 , V_111 ) ;
if ( V_73 > 1 )
fprintf ( V_16 , L_104
L_105 ) ;
if ( V_73 > 1 )
fprintf ( V_16 , L_106 ) ;
F_50 () ;
if ( V_117 - V_120 )
return F_51 ( V_111 + V_120 ) ;
else
F_36 () ;
return 0 ;
}
