void F_1 ( int V_1 )
{
V_2 = F_2 ( V_1 ) ;
if ( V_2 == NULL ) {
perror ( L_1 ) ;
exit ( 3 ) ;
}
V_3 = F_3 ( V_1 ) ;
F_4 ( V_3 , V_2 ) ;
}
void F_5 ()
{
F_6 ( V_2 ) ;
V_2 = NULL ;
V_3 = 0 ;
}
int F_7 ( int V_4 )
{
F_4 ( V_3 , V_2 ) ;
F_8 ( V_4 , V_3 , V_2 ) ;
if ( F_9 ( 0 , V_3 , V_2 ) == - 1 )
return - 1 ;
else
return 0 ;
}
int F_10 ( int V_4 , T_1 V_5 , unsigned long long * V_6 )
{
T_2 V_7 ;
char V_8 [ 32 ] ;
int V_9 ;
sprintf ( V_8 , L_2 , V_4 ) ;
V_9 = F_11 ( V_8 , V_10 ) ;
if ( V_9 < 0 )
return - 1 ;
V_7 = F_12 ( V_9 , V_6 , sizeof *V_6 , V_5 ) ;
F_13 ( V_9 ) ;
if ( V_7 != sizeof *V_6 )
return - 1 ;
return 0 ;
}
void F_14 ( void )
{
if ( V_11 )
fprintf ( V_12 , L_3 ) ;
if ( V_11 )
fprintf ( V_12 , L_4 ) ;
if ( V_13 )
fprintf ( V_12 , L_5 ) ;
if ( V_14 )
fprintf ( V_12 , L_6 ) ;
if ( V_11 || V_13 || V_14 )
fprintf ( V_12 , L_4 ) ;
if ( V_15 )
fprintf ( V_12 , L_7 ) ;
if ( V_16 )
fprintf ( V_12 , L_8 ) ;
fprintf ( V_12 , L_9 ) ;
if ( V_15 )
fprintf ( V_12 , L_10 ) ;
if ( V_15 )
fprintf ( V_12 , L_11 ) ;
if ( V_15 )
fprintf ( V_12 , L_12 ) ;
if ( V_17 )
fprintf ( V_12 , L_13 ) ;
if ( V_17 )
fprintf ( V_12 , L_14 ) ;
if ( V_15 )
fprintf ( V_12 , L_15 ) ;
if ( V_15 )
fprintf ( V_12 , L_16 ) ;
if ( V_17 )
fprintf ( V_12 , L_17 ) ;
if ( V_18 )
fprintf ( V_12 , L_18 , V_18 ) ;
putc ( '\n' , V_12 ) ;
}
void F_15 ( struct V_19 * V_20 )
{
if ( ! V_20 )
return;
if ( V_20 -> V_21 ) fprintf ( V_12 , L_19 , V_20 -> V_21 ) ;
if ( V_20 -> V_22 ) fprintf ( V_12 , L_20 , V_20 -> V_22 ) ;
if ( V_20 -> V_4 ) fprintf ( V_12 , L_21 , V_20 -> V_4 ) ;
if ( V_20 -> V_23 ) fprintf ( V_12 , L_22 , V_20 -> V_23 ) ;
if ( V_20 -> V_24 ) fprintf ( V_12 , L_23 , V_20 -> V_24 ) ;
if ( V_20 -> V_25 ) fprintf ( V_12 , L_24 , V_20 -> V_25 ) ;
if ( V_20 -> V_26 ) fprintf ( V_12 , L_25 , V_20 -> V_26 ) ;
if ( V_20 -> V_27 ) fprintf ( V_12 , L_26 , V_20 -> V_27 ) ;
if ( V_20 -> V_28 ) fprintf ( V_12 , L_27 , V_20 -> V_28 ) ;
if ( V_20 -> V_29 ) fprintf ( V_12 , L_28 , V_20 -> V_29 ) ;
if ( V_20 -> V_30 ) fprintf ( V_12 , L_29 , V_20 -> V_30 ) ;
if ( V_20 -> V_31 ) fprintf ( V_12 , L_30 , V_20 -> V_31 ) ;
if ( V_20 -> V_32 ) fprintf ( V_12 , L_31 , V_18 , V_20 -> V_32 ) ;
}
void F_16 ( struct V_19 * V_20 )
{
printf ( L_32 , V_20 ) ;
for (; V_20 ; V_20 = V_20 -> V_33 )
F_15 ( V_20 ) ;
}
void F_17 ( struct V_19 * V_34 )
{
double V_35 ;
V_35 = V_36 . V_37 + V_36 . V_38 / 1000000.0 ;
if ( V_34 == V_39 ) {
if ( V_11 )
fprintf ( V_12 , L_33 ) ;
if ( V_11 && V_13 )
fprintf ( V_12 , L_4 ) ;
if ( V_13 )
fprintf ( V_12 , L_34 ) ;
if ( V_14 )
fprintf ( V_12 , L_4 L_34 ) ;
} else {
if ( V_11 )
fprintf ( V_12 , L_35 , V_34 -> V_21 ) ;
if ( V_11 && V_13 )
fprintf ( V_12 , L_4 ) ;
if ( V_13 )
fprintf ( V_12 , L_36 , V_34 -> V_22 ) ;
if ( V_14 )
fprintf ( V_12 , L_37 , V_34 -> V_4 ) ;
}
if ( V_15 ) {
if ( V_11 || V_13 || V_14 )
fprintf ( V_12 , L_4 ) ;
if ( ! V_40 )
fprintf ( V_12 , L_38 , 100.0 * V_34 -> V_41 / V_34 -> V_23 ) ;
else
fprintf ( V_12 , L_39 ) ;
}
if ( V_16 ) {
if ( ! V_42 ) {
fprintf ( V_12 , L_40 ,
1.0 * V_34 -> V_23 / V_43 * V_34 -> V_27 /
V_34 -> V_41 / V_35 ) ;
} else {
if ( V_34 -> V_27 > V_34 -> V_23 || V_34 -> V_41 > V_34 -> V_23 ) {
fprintf ( V_12 , L_41 ) ;
} else {
fprintf ( V_12 , L_42 ,
1.0 * V_34 -> V_23 /
V_43 * V_34 -> V_27 /
V_34 -> V_41 / V_35 ) ;
}
}
}
fprintf ( V_12 , L_43 , 1.0 * V_34 -> V_23 / V_43 / V_35 ) ;
if ( V_15 ) {
if ( ! V_44 )
fprintf ( V_12 , L_44 , 100.0 * V_34 -> V_45 / V_34 -> V_23 ) ;
else
fprintf ( V_12 , L_39 ) ;
}
if ( V_15 )
fprintf ( V_12 , L_44 , 100.0 * V_34 -> V_24 / V_34 -> V_23 ) ;
if ( V_15 )
fprintf ( V_12 , L_44 , 100.0 * V_34 -> V_25 / V_34 -> V_23 ) ;
if ( V_17 )
fprintf ( V_12 , L_44 , 100.0 * V_34 -> V_26 / V_34 -> V_23 ) ;
if ( V_17 )
fprintf ( V_12 , L_44 , 100.0 * V_34 -> V_28 / V_34 -> V_23 ) ;
if ( V_15 )
fprintf ( V_12 , L_44 , 100.0 * V_34 -> V_29 / V_34 -> V_23 ) ;
if ( V_15 )
fprintf ( V_12 , L_44 , 100.0 * V_34 -> V_30 / V_34 -> V_23 ) ;
if ( V_17 )
fprintf ( V_12 , L_44 , 100.0 * V_34 -> V_31 / V_34 -> V_23 ) ;
if ( V_18 )
fprintf ( V_12 , L_45 , V_34 -> V_32 ) ;
putc ( '\n' , V_12 ) ;
}
void F_18 ( struct V_19 * V_19 )
{
struct V_19 * V_20 ;
static int V_46 ;
if ( ! V_46 || ! V_47 )
F_14 () ;
if ( V_48 > 1 )
F_17 ( V_39 ) ;
V_46 = 1 ;
if ( V_47 )
return;
for ( V_20 = V_19 ; V_20 != NULL ; V_20 = V_20 -> V_33 )
F_17 ( V_20 ) ;
}
int F_19 ( struct V_19 * V_49 ,
struct V_19 * V_50 , struct V_19 * V_51 )
{
int V_52 = 0 ;
int V_53 = 0 ;
V_40 = V_44 = 0 ;
for ( ; V_49 && V_50 && V_51 ;
V_49 = V_49 -> V_33 , V_50 = V_50 -> V_33 , V_51 = V_51 -> V_33 ) {
if ( V_50 -> V_4 != V_49 -> V_4 ) {
printf ( L_46 ,
V_50 -> V_4 , V_49 -> V_4 ) ;
return - 1 ;
}
if ( F_20 ( V_49 -> V_23 , V_50 -> V_23 , V_51 -> V_23 ) ) {
fprintf ( V_12 , L_47 ,
V_50 -> V_4 , V_50 -> V_23 , V_49 -> V_23 ) ;
V_52 ++ ;
}
if ( V_51 -> V_23 < ( 1000 * 1000 ) ) {
fprintf ( V_12 , L_48
L_49 ) ;
fprintf ( V_12 , L_50
L_51 ) ;
fprintf ( V_12 , L_52
L_53 ) ;
exit ( - 3 ) ;
}
if ( F_20 ( V_49 -> V_24 , V_50 -> V_24 , V_51 -> V_24 ) ) {
fprintf ( V_12 , L_54 ,
V_50 -> V_4 , V_50 -> V_24 , V_49 -> V_24 ) ;
V_52 ++ ;
}
if ( F_20 ( V_49 -> V_25 , V_50 -> V_25 , V_51 -> V_25 ) ) {
fprintf ( V_12 , L_55 ,
V_50 -> V_4 , V_50 -> V_25 , V_49 -> V_25 ) ;
V_52 ++ ;
}
if ( F_20 ( V_49 -> V_26 , V_50 -> V_26 , V_51 -> V_26 ) ) {
fprintf ( V_12 , L_56 ,
V_50 -> V_4 , V_50 -> V_26 , V_49 -> V_26 ) ;
V_52 ++ ;
}
if ( F_20 ( V_49 -> V_28 , V_50 -> V_28 , V_51 -> V_28 ) ) {
fprintf ( V_12 , L_57 ,
V_50 -> V_4 , V_50 -> V_28 , V_49 -> V_28 ) ;
V_52 ++ ;
}
if ( F_20 ( V_49 -> V_29 , V_50 -> V_29 , V_51 -> V_29 ) ) {
fprintf ( V_12 , L_58 ,
V_50 -> V_4 , V_50 -> V_29 , V_49 -> V_29 ) ;
V_52 ++ ;
}
if ( F_20 ( V_49 -> V_30 , V_50 -> V_30 , V_51 -> V_30 ) ) {
fprintf ( V_12 , L_59 ,
V_50 -> V_4 , V_50 -> V_30 , V_49 -> V_30 ) ;
V_52 ++ ;
}
if ( F_20 ( V_49 -> V_31 , V_50 -> V_31 , V_51 -> V_31 ) ) {
fprintf ( V_12 , L_60 ,
V_50 -> V_4 , V_50 -> V_31 , V_49 -> V_31 ) ;
V_52 ++ ;
}
V_53 = F_20 ( V_49 -> V_27 , V_50 -> V_27 , V_51 -> V_27 ) ;
if ( V_53 ) {
fprintf ( V_12 , L_61 ,
V_50 -> V_4 , V_50 -> V_27 , V_49 -> V_27 ) ;
}
V_53 |= F_20 ( V_49 -> V_41 , V_50 -> V_41 , V_51 -> V_41 ) ;
if ( V_53 ) {
fprintf ( V_12 , L_62 ,
V_50 -> V_4 , V_50 -> V_41 , V_49 -> V_41 ) ;
}
if ( V_53 ) {
if ( ! V_42 ) {
fprintf ( V_12 , L_63 , V_54 ) ;
fprintf ( V_12 , L_64 ) ;
fprintf ( V_12 , L_65 ) ;
V_42 = 1 ;
}
V_40 = 1 ;
V_44 = 1 ;
}
if ( V_51 -> V_41 > V_51 -> V_23 )
V_51 -> V_45 = 0 ;
else
V_51 -> V_45 = V_51 -> V_23 - V_51 -> V_41
- V_51 -> V_24 - V_51 -> V_25 - V_51 -> V_26 ;
if ( V_51 -> V_41 == 0 )
V_51 -> V_41 = 1 ;
V_51 -> V_32 = V_49 -> V_32 ;
if ( V_52 ) {
fprintf ( V_12 , L_66 , V_50 -> V_4 ) ;
F_15 ( V_50 ) ;
fprintf ( V_12 , L_67 , V_50 -> V_4 ) ;
F_15 ( V_49 ) ;
V_52 = 0 ;
}
}
return 0 ;
}
void F_21 ( struct V_19 * V_51 , struct V_19 * V_55 )
{
struct V_19 * V_56 ;
V_56 = calloc ( 1 , sizeof( struct V_19 ) ) ;
if ( V_56 == NULL ) {
perror ( L_68 ) ;
exit ( 1 ) ;
}
for (; V_51 ; V_51 = V_51 -> V_33 ) {
V_56 -> V_23 += V_51 -> V_23 ;
V_56 -> V_45 += V_51 -> V_45 ;
V_56 -> V_24 += V_51 -> V_24 ;
V_56 -> V_25 += V_51 -> V_25 ;
V_56 -> V_26 += V_51 -> V_26 ;
V_56 -> V_27 += V_51 -> V_27 ;
V_56 -> V_41 += V_51 -> V_41 ;
V_56 -> V_28 += V_51 -> V_28 ;
V_56 -> V_29 += V_51 -> V_29 ;
V_56 -> V_30 += V_51 -> V_30 ;
V_56 -> V_31 += V_51 -> V_31 ;
}
V_55 -> V_23 = V_56 -> V_23 / V_48 ;
V_55 -> V_45 = V_56 -> V_45 / V_48 ;
V_55 -> V_24 = V_56 -> V_24 / V_48 ;
V_55 -> V_25 = V_56 -> V_25 / V_48 ;
V_55 -> V_26 = V_56 -> V_26 / V_48 ;
V_55 -> V_27 = V_56 -> V_27 / V_48 ;
V_55 -> V_41 = V_56 -> V_41 / V_48 ;
V_55 -> V_28 = V_56 -> V_28 / V_48 ;
V_55 -> V_29 = V_56 -> V_29 / V_48 ;
V_55 -> V_30 = V_56 -> V_30 / V_48 ;
V_55 -> V_31 = V_56 -> V_31 / V_48 ;
free ( V_56 ) ;
}
int F_22 ( struct V_19 * V_20 )
{
for ( ; V_20 ; V_20 = V_20 -> V_33 ) {
if ( F_7 ( V_20 -> V_4 ) )
return - 1 ;
if ( F_10 ( V_20 -> V_4 , V_57 , & V_20 -> V_23 ) )
return - 1 ;
if ( V_16 ) {
if ( F_10 ( V_20 -> V_4 , V_58 , & V_20 -> V_27 ) )
return - 1 ;
if ( F_10 ( V_20 -> V_4 , V_59 , & V_20 -> V_41 ) )
return - 1 ;
}
if ( V_15 ) {
if ( F_10 ( V_20 -> V_4 , V_60 , & V_20 -> V_24 ) )
return - 1 ;
if ( F_10 ( V_20 -> V_4 , V_61 , & V_20 -> V_25 ) )
return - 1 ;
}
if ( V_17 )
if ( F_10 ( V_20 -> V_4 , V_62 , & V_20 -> V_26 ) )
return - 1 ;
if ( V_15 ) {
if ( F_10 ( V_20 -> V_4 , V_63 , & V_20 -> V_29 ) )
return - 1 ;
if ( F_10 ( V_20 -> V_4 , V_64 , & V_20 -> V_30 ) )
return - 1 ;
}
if ( V_17 ) {
if ( F_10 ( V_20 -> V_4 , V_65 , & V_20 -> V_28 ) )
return - 1 ;
if ( F_10 ( V_20 -> V_4 , V_66 , & V_20 -> V_31 ) )
return - 1 ;
}
if ( V_18 )
if ( F_10 ( V_20 -> V_4 , V_18 , & V_20 -> V_32 ) )
return - 1 ;
}
return 0 ;
}
void F_23 ( void )
{
unsigned long long V_6 ;
unsigned int V_67 ;
if ( ! V_68 )
return;
F_10 ( 0 , V_69 , & V_6 ) ;
V_67 = ( V_6 >> 40 ) & 0xFF ;
fprintf ( V_12 , L_69 ,
V_67 , V_70 , V_67 * V_70 ) ;
V_67 = ( V_6 >> 8 ) & 0xFF ;
fprintf ( V_12 , L_70 ,
V_67 , V_70 , V_67 * V_70 ) ;
if ( V_71 > 1 )
fprintf ( V_12 , L_71 , V_6 ) ;
if ( ! V_72 )
return;
F_10 ( 0 , V_73 , & V_6 ) ;
V_67 = ( V_6 >> 24 ) & 0xFF ;
if ( V_67 )
fprintf ( V_12 , L_72 ,
V_67 , V_70 , V_67 * V_70 ) ;
V_67 = ( V_6 >> 16 ) & 0xFF ;
if ( V_67 )
fprintf ( V_12 , L_73 ,
V_67 , V_70 , V_67 * V_70 ) ;
V_67 = ( V_6 >> 8 ) & 0xFF ;
if ( V_67 )
fprintf ( V_12 , L_74 ,
V_67 , V_70 , V_67 * V_70 ) ;
V_67 = ( V_6 >> 0 ) & 0xFF ;
if ( V_67 )
fprintf ( V_12 , L_75 ,
V_67 , V_70 , V_67 * V_70 ) ;
}
void F_24 ( struct V_19 * V_74 )
{
struct V_19 * V_34 ;
for ( V_34 = V_74 ; V_34 ; ) {
struct V_19 * V_75 ;
V_75 = V_34 ;
V_34 = V_34 -> V_33 ;
free ( V_75 ) ;
}
}
void F_25 ( void )
{
F_24 ( V_76 ) ;
V_76 = NULL ;
F_24 ( V_77 ) ;
V_77 = NULL ;
F_24 ( V_78 ) ;
V_78 = NULL ;
F_24 ( V_39 ) ;
V_39 = NULL ;
}
void F_26 ( struct V_19 * * V_74 ,
struct V_19 * V_79 )
{
struct V_19 * V_80 ;
if ( * V_74 == NULL ) {
V_79 -> V_33 = * V_74 ;
* V_74 = V_79 ;
return;
}
if ( ! V_47 )
V_14 = 1 ;
if ( ( ( * V_74 ) -> V_21 > V_79 -> V_21 ) ||
( ( ( * V_74 ) -> V_21 == V_79 -> V_21 ) && ( ( * V_74 ) -> V_22 > V_79 -> V_22 ) ) ||
( ( ( * V_74 ) -> V_21 == V_79 -> V_21 ) && ( ( * V_74 ) -> V_22 == V_79 -> V_22 ) && ( ( * V_74 ) -> V_4 > V_79 -> V_4 ) ) ) {
V_79 -> V_33 = * V_74 ;
* V_74 = V_79 ;
return;
}
V_80 = * V_74 ;
while ( V_80 -> V_33 && ( V_80 -> V_33 -> V_21 < V_79 -> V_21 ) ) {
V_80 = V_80 -> V_33 ;
if ( ! V_47 )
V_11 = 1 ;
}
while ( V_80 -> V_33 && ( V_80 -> V_33 -> V_21 == V_79 -> V_21 )
&& ( V_80 -> V_33 -> V_22 < V_79 -> V_22 ) ) {
V_80 = V_80 -> V_33 ;
if ( ! V_47 )
V_13 = 1 ;
}
while ( V_80 -> V_33 && ( V_80 -> V_33 -> V_21 == V_79 -> V_21 )
&& ( V_80 -> V_33 -> V_22 == V_79 -> V_22 )
&& ( V_80 -> V_33 -> V_4 < V_79 -> V_4 ) ) {
V_80 = V_80 -> V_33 ;
}
V_79 -> V_33 = V_80 -> V_33 ;
V_80 -> V_33 = V_79 ;
}
void F_27 ( int V_21 , int V_22 , int V_4 )
{
struct V_19 * V_79 ;
if ( V_71 > 1 )
printf ( L_76 , V_21 , V_22 , V_4 ) ;
V_79 = (struct V_19 * ) calloc ( 1 , sizeof( struct V_19 ) ) ;
if ( V_79 == NULL ) {
perror ( L_77 ) ;
exit ( 1 ) ;
}
V_79 -> V_21 = V_21 ;
V_79 -> V_22 = V_22 ;
V_79 -> V_4 = V_4 ;
F_26 ( & V_77 , V_79 ) ;
V_79 = (struct V_19 * ) calloc ( 1 ,
sizeof( struct V_19 ) ) ;
if ( V_79 == NULL ) {
perror ( L_77 ) ;
exit ( 1 ) ;
}
V_79 -> V_21 = V_21 ;
V_79 -> V_22 = V_22 ;
V_79 -> V_4 = V_4 ;
F_26 ( & V_76 , V_79 ) ;
V_79 = (struct V_19 * ) calloc ( 1 , sizeof( struct V_19 ) ) ;
if ( V_79 == NULL ) {
perror ( L_77 ) ;
exit ( 1 ) ;
}
V_79 -> V_21 = V_21 ;
V_79 -> V_22 = V_22 ;
V_79 -> V_4 = V_4 ;
F_26 ( & V_78 , V_79 ) ;
V_79 = (struct V_19 * ) calloc ( 1 , sizeof( struct V_19 ) ) ;
if ( V_79 == NULL ) {
perror ( L_77 ) ;
exit ( 1 ) ;
}
V_79 -> V_21 = V_21 ;
V_79 -> V_22 = V_22 ;
V_79 -> V_4 = V_4 ;
V_39 = V_79 ;
}
int F_28 ( int V_4 )
{
char V_81 [ 64 ] ;
T_3 * V_82 ;
int V_21 ;
sprintf ( V_81 , L_78 , V_4 ) ;
V_82 = fopen ( V_81 , L_79 ) ;
if ( V_82 == NULL ) {
perror ( V_81 ) ;
exit ( 1 ) ;
}
fscanf ( V_82 , L_80 , & V_21 ) ;
fclose ( V_82 ) ;
return V_21 ;
}
int F_29 ( int V_4 )
{
char V_81 [ 64 ] ;
T_3 * V_82 ;
int V_22 ;
sprintf ( V_81 , L_81 , V_4 ) ;
V_82 = fopen ( V_81 , L_79 ) ;
if ( V_82 == NULL ) {
perror ( V_81 ) ;
exit ( 1 ) ;
}
fscanf ( V_82 , L_80 , & V_22 ) ;
fclose ( V_82 ) ;
return V_22 ;
}
int F_30 ( void (F_31)( int , int , int ) )
{
T_3 * V_83 ;
int V_84 ;
int V_7 ;
V_83 = fopen ( V_85 , L_79 ) ;
if ( V_83 == NULL ) {
perror ( V_85 ) ;
exit ( 1 ) ;
}
V_7 = fscanf ( V_83 , L_82 ) ;
if ( V_7 != 0 ) {
perror ( L_83 ) ;
exit ( 1 ) ;
}
for ( V_84 = 0 ; ; V_84 ++ ) {
int V_4 ;
V_7 = fscanf ( V_83 , L_84 , & V_4 ) ;
if ( V_7 != 1 )
break;
F_31 ( F_28 ( V_4 ) , F_29 ( V_4 ) , V_4 ) ;
}
fclose ( V_83 ) ;
return V_84 ;
}
void F_32 ( void )
{
F_25 () ;
V_48 = F_30 ( F_27 ) ;
F_5 () ;
F_1 ( V_48 ) ;
printf ( L_85 , V_48 ) ;
}
void F_33 ( int V_21 , int V_22 , int V_4 ) { return; }
int F_34 ( void )
{
int V_86 ;
V_86 = F_30 ( F_33 ) ;
if ( V_86 != V_48 ) {
if ( V_71 )
printf ( L_86 ,
V_48 , V_86 ) ;
return - 1 ;
}
return 0 ;
}
void F_35 ()
{
V_87:
F_22 ( V_76 ) ;
F_36 ( & V_88 , (struct V_89 * ) NULL ) ;
while ( 1 ) {
if ( F_34 () ) {
F_32 () ;
goto V_87;
}
F_37 ( V_90 ) ;
if ( F_22 ( V_77 ) ) {
F_32 () ;
goto V_87;
}
F_36 ( & V_91 , (struct V_89 * ) NULL ) ;
F_19 ( V_77 , V_76 , V_78 ) ;
F_38 ( & V_91 , & V_88 , & V_36 ) ;
F_21 ( V_78 , V_39 ) ;
F_18 ( V_78 ) ;
F_37 ( V_90 ) ;
if ( F_22 ( V_76 ) ) {
F_32 () ;
goto V_87;
}
F_36 ( & V_88 , (struct V_89 * ) NULL ) ;
F_19 ( V_76 , V_77 , V_78 ) ;
F_38 ( & V_88 , & V_91 , & V_36 ) ;
F_21 ( V_78 , V_39 ) ;
F_18 ( V_78 ) ;
}
}
void F_39 ()
{
struct V_92 V_93 ;
if ( V_92 ( L_87 , & V_93 ) ) {
fprintf ( V_12 , L_88 ) ;
fprintf ( V_12 , L_89 ) ;
exit ( - 5 ) ;
}
}
void F_40 ()
{
if ( F_41 () != 0 ) {
fprintf ( V_12 , L_90 ) ;
exit ( - 6 ) ;
}
}
int F_42 ( unsigned int V_94 , unsigned int V_95 )
{
if ( ! V_96 )
return 0 ;
if ( V_94 != 6 )
return 0 ;
switch ( V_95 ) {
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
int F_43 ( unsigned int V_94 , unsigned int V_95 )
{
if ( ! V_96 )
return 0 ;
switch ( V_95 ) {
case 0x2A :
case 0x2D :
return 1 ;
}
return 0 ;
}
double F_44 ( unsigned int V_94 , unsigned int V_95 )
{
if ( F_43 ( V_94 , V_95 ) )
return 100.00 ;
else
return 133.33 ;
}
void F_45 ()
{
unsigned int V_97 , V_98 , V_99 , V_100 , V_101 ;
unsigned int V_102 , V_94 , V_95 , V_103 ;
V_97 = V_98 = V_99 = V_100 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0));
if ( V_98 == 0x756e6547 && V_100 == 0x49656e69 && V_99 == 0x6c65746e )
V_96 = 1 ;
if ( V_71 )
fprintf ( V_12 , L_91 ,
( char * ) & V_98 , ( char * ) & V_100 , ( char * ) & V_99 ) ;
asm("cpuid" : "=a" (fms), "=c" (ecx), "=d" (edx) : "a" (1) : "ebx");
V_94 = ( V_102 >> 8 ) & 0xf ;
V_95 = ( V_102 >> 4 ) & 0xf ;
V_103 = V_102 & 0xf ;
if ( V_94 == 6 || V_94 == 0xf )
V_95 += ( ( V_102 >> 16 ) & 0xf ) << 4 ;
if ( V_71 )
fprintf ( V_12 , L_92 ,
V_101 , V_94 , V_95 , V_103 , V_94 , V_95 , V_103 ) ;
if ( ! ( V_100 & ( 1 << 5 ) ) ) {
fprintf ( V_12 , L_93 ) ;
exit ( 1 ) ;
}
V_98 = V_99 = V_100 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000000));
if ( V_101 < 0x80000007 ) {
fprintf ( V_12 , L_94 , V_101 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000007));
V_104 = V_100 & ( 1 << 8 ) ;
if ( ! V_104 ) {
fprintf ( V_12 , L_95 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x6));
V_16 = V_99 & ( 1 << 0 ) ;
if ( ! V_16 ) {
fprintf ( V_12 , L_96 ) ;
exit ( 1 ) ;
}
V_68 = V_96 && V_104 ;
V_15 = V_96 ;
V_17 = F_43 ( V_94 , V_95 ) ;
V_70 = F_44 ( V_94 , V_95 ) ;
V_72 = F_42 ( V_94 , V_95 ) ;
}
void F_46 ()
{
fprintf ( V_12 , L_97 ,
V_54 ) ;
exit ( 1 ) ;
}
int F_47 ( const struct V_105 * V_106 )
{
if ( isdigit ( V_106 -> V_107 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_48 ( int V_108 )
{
return 0 ;
}
void F_49 ()
{
F_45 () ;
F_39 () ;
F_40 () ;
V_48 = F_30 ( F_27 ) ;
F_1 ( V_48 ) ;
if ( V_71 )
F_23 () ;
}
int F_50 ( char * * V_109 )
{
int V_7 ;
T_4 V_110 ;
F_22 ( V_76 ) ;
F_36 ( & V_88 , (struct V_89 * ) NULL ) ;
V_110 = F_51 () ;
if ( ! V_110 ) {
F_52 ( V_109 [ 0 ] , V_109 ) ;
} else {
int V_111 ;
if ( V_110 == - 1 ) {
perror ( L_98 ) ;
exit ( 1 ) ;
}
signal ( V_112 , V_113 ) ;
signal ( V_114 , V_113 ) ;
if ( F_53 ( V_110 , & V_111 , 0 ) == - 1 ) {
perror ( L_99 ) ;
exit ( 1 ) ;
}
}
F_22 ( V_77 ) ;
F_36 ( & V_91 , (struct V_89 * ) NULL ) ;
V_7 = F_19 ( V_77 , V_76 , V_78 ) ;
F_38 ( & V_91 , & V_88 , & V_36 ) ;
F_21 ( V_78 , V_39 ) ;
if ( ! V_7 )
F_18 ( V_78 ) ;
fprintf ( V_12 , L_100 , V_36 . V_37 + V_36 . V_38 / 1000000.0 ) ;
return 0 ;
}
void F_54 ( int V_115 , char * * V_109 )
{
int V_116 ;
V_54 = V_109 [ 0 ] ;
while ( ( V_116 = F_55 ( V_115 , V_109 , L_101 ) ) != - 1 ) {
switch ( V_116 ) {
case 's' :
V_47 ++ ;
break;
case 'v' :
V_71 ++ ;
break;
case 'i' :
V_90 = atoi ( V_117 ) ;
break;
case 'M' :
sscanf ( V_117 , L_102 , & V_18 ) ;
if ( V_71 > 1 )
fprintf ( V_12 , L_103 , V_18 ) ;
break;
default:
F_46 () ;
}
}
}
int main ( int V_115 , char * * V_109 )
{
F_54 ( V_115 , V_109 ) ;
if ( V_71 > 1 )
fprintf ( V_12 , L_104
L_105 ) ;
if ( V_71 > 1 )
fprintf ( V_12 , L_106 ) ;
F_49 () ;
if ( V_115 - V_118 )
return F_50 ( V_109 + V_118 ) ;
else
F_35 () ;
return 0 ;
}
