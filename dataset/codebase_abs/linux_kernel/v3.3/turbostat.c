unsigned long long F_1 ( int V_1 , T_1 V_2 )
{
T_2 V_3 ;
unsigned long long V_4 ;
char V_5 [ 32 ] ;
int V_6 ;
sprintf ( V_5 , L_1 , V_1 ) ;
V_6 = F_2 ( V_5 , V_7 ) ;
if ( V_6 < 0 ) {
perror ( V_5 ) ;
V_8 = 1 ;
return 0 ;
}
V_3 = F_3 ( V_6 , & V_4 , sizeof V_4 , V_2 ) ;
if ( V_3 != sizeof V_4 ) {
fprintf ( V_9 , L_2 ,
V_1 , V_2 , V_3 ) ;
exit ( - 2 ) ;
}
F_4 ( V_6 ) ;
return V_4 ;
}
void F_5 ( void )
{
if ( V_10 )
fprintf ( V_9 , L_3 ) ;
if ( V_11 )
fprintf ( V_9 , L_4 ) ;
if ( V_12 )
fprintf ( V_9 , L_5 ) ;
if ( V_13 )
fprintf ( V_9 , L_6 ) ;
if ( V_14 )
fprintf ( V_9 , L_7 ) ;
fprintf ( V_9 , L_8 ) ;
if ( V_13 )
fprintf ( V_9 , L_9 ) ;
if ( V_13 )
fprintf ( V_9 , L_10 ) ;
if ( V_13 )
fprintf ( V_9 , L_11 ) ;
if ( V_15 )
fprintf ( V_9 , L_12 ) ;
if ( V_15 )
fprintf ( V_9 , L_13 ) ;
if ( V_13 )
fprintf ( V_9 , L_14 ) ;
if ( V_13 )
fprintf ( V_9 , L_15 ) ;
if ( V_15 )
fprintf ( V_9 , L_16 ) ;
if ( V_16 )
fprintf ( V_9 , L_17 , V_16 ) ;
putc ( '\n' , V_9 ) ;
}
void F_6 ( struct V_17 * V_18 )
{
if ( ! V_18 )
return;
if ( V_18 -> V_19 ) fprintf ( V_9 , L_18 , V_18 -> V_19 ) ;
if ( V_18 -> V_20 ) fprintf ( V_9 , L_19 , V_18 -> V_20 ) ;
if ( V_18 -> V_1 ) fprintf ( V_9 , L_20 , V_18 -> V_1 ) ;
if ( V_18 -> V_21 ) fprintf ( V_9 , L_21 , V_18 -> V_21 ) ;
if ( V_18 -> V_22 ) fprintf ( V_9 , L_22 , V_18 -> V_22 ) ;
if ( V_18 -> V_23 ) fprintf ( V_9 , L_23 , V_18 -> V_23 ) ;
if ( V_18 -> V_24 ) fprintf ( V_9 , L_24 , V_18 -> V_24 ) ;
if ( V_18 -> V_25 ) fprintf ( V_9 , L_25 , V_18 -> V_25 ) ;
if ( V_18 -> V_26 ) fprintf ( V_9 , L_26 , V_18 -> V_26 ) ;
if ( V_18 -> V_27 ) fprintf ( V_9 , L_27 , V_18 -> V_27 ) ;
if ( V_18 -> V_28 ) fprintf ( V_9 , L_28 , V_18 -> V_28 ) ;
if ( V_18 -> V_29 ) fprintf ( V_9 , L_29 , V_18 -> V_29 ) ;
if ( V_18 -> V_30 ) fprintf ( V_9 , L_30 , V_16 , V_18 -> V_30 ) ;
}
void F_7 ( struct V_17 * V_18 )
{
printf ( L_31 , V_18 ) ;
for (; V_18 ; V_18 = V_18 -> V_31 )
F_6 ( V_18 ) ;
}
void F_8 ( struct V_17 * V_32 )
{
double V_33 ;
V_33 = V_34 . V_35 + V_34 . V_36 / 1000000.0 ;
if ( V_32 == V_37 ) {
if ( V_10 )
fprintf ( V_9 , L_32 ) ;
if ( V_11 )
fprintf ( V_9 , L_33 ) ;
if ( V_12 )
fprintf ( V_9 , L_33 ) ;
} else {
if ( V_10 )
fprintf ( V_9 , L_34 , V_32 -> V_19 ) ;
if ( V_11 )
fprintf ( V_9 , L_35 , V_32 -> V_20 ) ;
if ( V_12 )
fprintf ( V_9 , L_35 , V_32 -> V_1 ) ;
}
if ( V_13 ) {
if ( ! V_38 )
fprintf ( V_9 , L_36 , 100.0 * V_32 -> V_39 / V_32 -> V_21 ) ;
else
fprintf ( V_9 , L_37 ) ;
}
if ( V_14 ) {
if ( ! V_40 ) {
fprintf ( V_9 , L_38 ,
1.0 * V_32 -> V_21 / V_41 * V_32 -> V_25 /
V_32 -> V_39 / V_33 ) ;
} else {
if ( V_32 -> V_25 > V_32 -> V_21 || V_32 -> V_39 > V_32 -> V_21 ) {
fprintf ( V_9 , L_39 ) ;
} else {
fprintf ( V_9 , L_40 ,
1.0 * V_32 -> V_21 /
V_41 * V_32 -> V_25 /
V_32 -> V_39 / V_33 ) ;
}
}
}
fprintf ( V_9 , L_38 , 1.0 * V_32 -> V_21 / V_41 / V_33 ) ;
if ( V_13 ) {
if ( ! V_42 )
fprintf ( V_9 , L_36 , 100.0 * V_32 -> V_43 / V_32 -> V_21 ) ;
else
fprintf ( V_9 , L_41 ) ;
}
if ( V_13 )
fprintf ( V_9 , L_42 , 100.0 * V_32 -> V_22 / V_32 -> V_21 ) ;
if ( V_13 )
fprintf ( V_9 , L_42 , 100.0 * V_32 -> V_23 / V_32 -> V_21 ) ;
if ( V_15 )
fprintf ( V_9 , L_42 , 100.0 * V_32 -> V_24 / V_32 -> V_21 ) ;
if ( V_15 )
fprintf ( V_9 , L_43 , 100.0 * V_32 -> V_26 / V_32 -> V_21 ) ;
if ( V_13 )
fprintf ( V_9 , L_43 , 100.0 * V_32 -> V_27 / V_32 -> V_21 ) ;
if ( V_13 )
fprintf ( V_9 , L_43 , 100.0 * V_32 -> V_28 / V_32 -> V_21 ) ;
if ( V_15 )
fprintf ( V_9 , L_43 , 100.0 * V_32 -> V_29 / V_32 -> V_21 ) ;
if ( V_16 )
fprintf ( V_9 , L_44 , V_32 -> V_30 ) ;
putc ( '\n' , V_9 ) ;
}
void F_9 ( struct V_17 * V_17 )
{
struct V_17 * V_18 ;
F_5 () ;
if ( V_44 > 1 )
F_8 ( V_37 ) ;
for ( V_18 = V_17 ; V_18 != NULL ; V_18 = V_18 -> V_31 )
F_8 ( V_18 ) ;
}
int F_10 ( struct V_17 * V_45 ,
struct V_17 * V_46 , struct V_17 * V_47 )
{
int V_48 = 0 ;
int V_49 = 0 ;
V_38 = V_42 = 0 ;
for ( ; V_45 && V_46 && V_47 ;
V_45 = V_45 -> V_31 , V_46 = V_46 -> V_31 , V_47 = V_47 -> V_31 ) {
if ( V_46 -> V_1 != V_45 -> V_1 ) {
printf ( L_45 ,
V_46 -> V_1 , V_45 -> V_1 ) ;
return - 1 ;
}
if ( F_11 ( V_45 -> V_21 , V_46 -> V_21 , V_47 -> V_21 ) ) {
fprintf ( V_9 , L_46 ,
V_46 -> V_1 , V_46 -> V_21 , V_45 -> V_21 ) ;
V_48 ++ ;
}
if ( V_47 -> V_21 < ( 1000 * 1000 ) ) {
fprintf ( V_9 , L_47
L_48 ) ;
fprintf ( V_9 , L_49
L_50 ) ;
fprintf ( V_9 , L_51
L_52 ) ;
exit ( - 3 ) ;
}
if ( F_11 ( V_45 -> V_22 , V_46 -> V_22 , V_47 -> V_22 ) ) {
fprintf ( V_9 , L_53 ,
V_46 -> V_1 , V_46 -> V_22 , V_45 -> V_22 ) ;
V_48 ++ ;
}
if ( F_11 ( V_45 -> V_23 , V_46 -> V_23 , V_47 -> V_23 ) ) {
fprintf ( V_9 , L_54 ,
V_46 -> V_1 , V_46 -> V_23 , V_45 -> V_23 ) ;
V_48 ++ ;
}
if ( F_11 ( V_45 -> V_24 , V_46 -> V_24 , V_47 -> V_24 ) ) {
fprintf ( V_9 , L_55 ,
V_46 -> V_1 , V_46 -> V_24 , V_45 -> V_24 ) ;
V_48 ++ ;
}
if ( F_11 ( V_45 -> V_26 , V_46 -> V_26 , V_47 -> V_26 ) ) {
fprintf ( V_9 , L_56 ,
V_46 -> V_1 , V_46 -> V_26 , V_45 -> V_26 ) ;
V_48 ++ ;
}
if ( F_11 ( V_45 -> V_27 , V_46 -> V_27 , V_47 -> V_27 ) ) {
fprintf ( V_9 , L_57 ,
V_46 -> V_1 , V_46 -> V_27 , V_45 -> V_27 ) ;
V_48 ++ ;
}
if ( F_11 ( V_45 -> V_28 , V_46 -> V_28 , V_47 -> V_28 ) ) {
fprintf ( V_9 , L_58 ,
V_46 -> V_1 , V_46 -> V_28 , V_45 -> V_28 ) ;
V_48 ++ ;
}
if ( F_11 ( V_45 -> V_29 , V_46 -> V_29 , V_47 -> V_29 ) ) {
fprintf ( V_9 , L_59 ,
V_46 -> V_1 , V_46 -> V_29 , V_45 -> V_29 ) ;
V_48 ++ ;
}
V_49 = F_11 ( V_45 -> V_25 , V_46 -> V_25 , V_47 -> V_25 ) ;
if ( V_49 ) {
fprintf ( V_9 , L_60 ,
V_46 -> V_1 , V_46 -> V_25 , V_45 -> V_25 ) ;
}
V_49 |= F_11 ( V_45 -> V_39 , V_46 -> V_39 , V_47 -> V_39 ) ;
if ( V_49 ) {
fprintf ( V_9 , L_61 ,
V_46 -> V_1 , V_46 -> V_39 , V_45 -> V_39 ) ;
}
if ( V_49 ) {
if ( ! V_40 ) {
fprintf ( V_9 , L_62 , V_50 ) ;
fprintf ( V_9 , L_63 ) ;
fprintf ( V_9 , L_64 ) ;
V_40 = 1 ;
}
V_38 = 1 ;
V_42 = 1 ;
}
if ( V_47 -> V_39 > V_47 -> V_21 )
V_47 -> V_43 = 0 ;
else
V_47 -> V_43 = V_47 -> V_21 - V_47 -> V_39
- V_47 -> V_22 - V_47 -> V_23 - V_47 -> V_24 ;
if ( V_47 -> V_39 == 0 )
V_47 -> V_39 = 1 ;
V_47 -> V_30 = V_45 -> V_30 ;
if ( V_48 ) {
fprintf ( V_9 , L_65 , V_46 -> V_1 ) ;
F_6 ( V_46 ) ;
fprintf ( V_9 , L_66 , V_46 -> V_1 ) ;
F_6 ( V_45 ) ;
V_48 = 0 ;
}
}
return 0 ;
}
void F_12 ( struct V_17 * V_47 , struct V_17 * V_51 )
{
struct V_17 * V_52 ;
V_52 = calloc ( 1 , sizeof( struct V_17 ) ) ;
if ( V_52 == NULL ) {
perror ( L_67 ) ;
exit ( 1 ) ;
}
for (; V_47 ; V_47 = V_47 -> V_31 ) {
V_52 -> V_21 += V_47 -> V_21 ;
V_52 -> V_43 += V_47 -> V_43 ;
V_52 -> V_22 += V_47 -> V_22 ;
V_52 -> V_23 += V_47 -> V_23 ;
V_52 -> V_24 += V_47 -> V_24 ;
V_52 -> V_25 += V_47 -> V_25 ;
V_52 -> V_39 += V_47 -> V_39 ;
V_52 -> V_26 += V_47 -> V_26 ;
V_52 -> V_27 += V_47 -> V_27 ;
V_52 -> V_28 += V_47 -> V_28 ;
V_52 -> V_29 += V_47 -> V_29 ;
}
V_51 -> V_21 = V_52 -> V_21 / V_44 ;
V_51 -> V_43 = V_52 -> V_43 / V_44 ;
V_51 -> V_22 = V_52 -> V_22 / V_44 ;
V_51 -> V_23 = V_52 -> V_23 / V_44 ;
V_51 -> V_24 = V_52 -> V_24 / V_44 ;
V_51 -> V_25 = V_52 -> V_25 / V_44 ;
V_51 -> V_39 = V_52 -> V_39 / V_44 ;
V_51 -> V_26 = V_52 -> V_26 / V_44 ;
V_51 -> V_27 = V_52 -> V_27 / V_44 ;
V_51 -> V_28 = V_52 -> V_28 / V_44 ;
V_51 -> V_29 = V_52 -> V_29 / V_44 ;
free ( V_52 ) ;
}
void F_13 ( struct V_17 * V_18 )
{
for ( ; V_18 ; V_18 = V_18 -> V_31 ) {
V_18 -> V_21 = F_1 ( V_18 -> V_1 , V_53 ) ;
if ( V_13 )
V_18 -> V_22 = F_1 ( V_18 -> V_1 , V_54 ) ;
if ( V_13 )
V_18 -> V_23 = F_1 ( V_18 -> V_1 , V_55 ) ;
if ( V_15 )
V_18 -> V_24 = F_1 ( V_18 -> V_1 , V_56 ) ;
if ( V_14 )
V_18 -> V_25 = F_1 ( V_18 -> V_1 , V_57 ) ;
if ( V_14 )
V_18 -> V_39 = F_1 ( V_18 -> V_1 , V_58 ) ;
if ( V_15 )
V_18 -> V_26 = F_1 ( V_18 -> V_1 , V_59 ) ;
if ( V_13 )
V_18 -> V_27 = F_1 ( V_18 -> V_1 , V_60 ) ;
if ( V_13 )
V_18 -> V_28 = F_1 ( V_18 -> V_1 , V_61 ) ;
if ( V_15 )
V_18 -> V_29 = F_1 ( V_18 -> V_1 , V_62 ) ;
if ( V_16 )
V_18 -> V_30 = F_1 ( V_18 -> V_1 , V_16 ) ;
}
}
void F_14 ( void )
{
unsigned long long V_4 ;
unsigned int V_63 ;
if ( ! V_64 )
return;
V_4 = F_1 ( 0 , V_65 ) ;
V_63 = ( V_4 >> 40 ) & 0xFF ;
fprintf ( V_9 , L_68 ,
V_63 , V_66 , V_63 * V_66 ) ;
V_63 = ( V_4 >> 8 ) & 0xFF ;
fprintf ( V_9 , L_69 ,
V_63 , V_66 , V_63 * V_66 ) ;
if ( V_67 > 1 )
fprintf ( V_9 , L_70 , V_4 ) ;
if ( ! V_68 )
return;
V_4 = F_1 ( 0 , V_69 ) ;
V_63 = ( V_4 >> 24 ) & 0xFF ;
if ( V_63 )
fprintf ( V_9 , L_71 ,
V_63 , V_66 , V_63 * V_66 ) ;
V_63 = ( V_4 >> 16 ) & 0xFF ;
if ( V_63 )
fprintf ( V_9 , L_72 ,
V_63 , V_66 , V_63 * V_66 ) ;
V_63 = ( V_4 >> 8 ) & 0xFF ;
if ( V_63 )
fprintf ( V_9 , L_73 ,
V_63 , V_66 , V_63 * V_66 ) ;
V_63 = ( V_4 >> 0 ) & 0xFF ;
if ( V_63 )
fprintf ( V_9 , L_74 ,
V_63 , V_66 , V_63 * V_66 ) ;
}
void F_15 ( struct V_17 * V_70 )
{
struct V_17 * V_32 ;
for ( V_32 = V_70 ; V_32 ; ) {
struct V_17 * V_71 ;
V_71 = V_32 ;
V_32 = V_32 -> V_31 ;
free ( V_71 ) ;
}
}
void F_16 ( void )
{
F_15 ( V_72 ) ;
V_72 = NULL ;
F_15 ( V_73 ) ;
V_73 = NULL ;
F_15 ( V_74 ) ;
V_74 = NULL ;
F_15 ( V_37 ) ;
V_37 = NULL ;
}
void F_17 ( struct V_17 * * V_70 ,
struct V_17 * V_75 )
{
struct V_17 * V_76 ;
if ( * V_70 == NULL ) {
V_75 -> V_31 = * V_70 ;
* V_70 = V_75 ;
return;
}
V_12 = 1 ;
if ( ( ( * V_70 ) -> V_19 > V_75 -> V_19 ) ||
( ( ( * V_70 ) -> V_19 == V_75 -> V_19 ) && ( ( * V_70 ) -> V_20 > V_75 -> V_20 ) ) ||
( ( ( * V_70 ) -> V_19 == V_75 -> V_19 ) && ( ( * V_70 ) -> V_20 == V_75 -> V_20 ) && ( ( * V_70 ) -> V_1 > V_75 -> V_1 ) ) ) {
V_75 -> V_31 = * V_70 ;
* V_70 = V_75 ;
return;
}
V_76 = * V_70 ;
while ( V_76 -> V_31 && ( V_76 -> V_31 -> V_19 < V_75 -> V_19 ) ) {
V_76 = V_76 -> V_31 ;
V_10 = 1 ;
}
while ( V_76 -> V_31 && ( V_76 -> V_31 -> V_19 == V_75 -> V_19 )
&& ( V_76 -> V_31 -> V_20 < V_75 -> V_20 ) ) {
V_76 = V_76 -> V_31 ;
V_11 = 1 ;
}
while ( V_76 -> V_31 && ( V_76 -> V_31 -> V_19 == V_75 -> V_19 )
&& ( V_76 -> V_31 -> V_20 == V_75 -> V_20 )
&& ( V_76 -> V_31 -> V_1 < V_75 -> V_1 ) ) {
V_76 = V_76 -> V_31 ;
}
V_75 -> V_31 = V_76 -> V_31 ;
V_76 -> V_31 = V_75 ;
}
void F_18 ( int V_19 , int V_20 , int V_1 )
{
struct V_17 * V_75 ;
if ( V_67 > 1 )
printf ( L_75 , V_19 , V_20 , V_1 ) ;
V_75 = (struct V_17 * ) calloc ( 1 , sizeof( struct V_17 ) ) ;
if ( V_75 == NULL ) {
perror ( L_76 ) ;
exit ( 1 ) ;
}
V_75 -> V_19 = V_19 ;
V_75 -> V_20 = V_20 ;
V_75 -> V_1 = V_1 ;
F_17 ( & V_73 , V_75 ) ;
V_75 = (struct V_17 * ) calloc ( 1 ,
sizeof( struct V_17 ) ) ;
if ( V_75 == NULL ) {
perror ( L_76 ) ;
exit ( 1 ) ;
}
V_75 -> V_19 = V_19 ;
V_75 -> V_20 = V_20 ;
V_75 -> V_1 = V_1 ;
F_17 ( & V_72 , V_75 ) ;
V_75 = (struct V_17 * ) calloc ( 1 , sizeof( struct V_17 ) ) ;
if ( V_75 == NULL ) {
perror ( L_76 ) ;
exit ( 1 ) ;
}
V_75 -> V_19 = V_19 ;
V_75 -> V_20 = V_20 ;
V_75 -> V_1 = V_1 ;
F_17 ( & V_74 , V_75 ) ;
V_75 = (struct V_17 * ) calloc ( 1 , sizeof( struct V_17 ) ) ;
if ( V_75 == NULL ) {
perror ( L_76 ) ;
exit ( 1 ) ;
}
V_75 -> V_19 = V_19 ;
V_75 -> V_20 = V_20 ;
V_75 -> V_1 = V_1 ;
V_37 = V_75 ;
}
int F_19 ( int V_1 )
{
char V_77 [ 64 ] ;
T_3 * V_78 ;
int V_19 ;
sprintf ( V_77 , L_77 , V_1 ) ;
V_78 = fopen ( V_77 , L_78 ) ;
if ( V_78 == NULL ) {
perror ( V_77 ) ;
exit ( 1 ) ;
}
fscanf ( V_78 , L_34 , & V_19 ) ;
fclose ( V_78 ) ;
return V_19 ;
}
int F_20 ( int V_1 )
{
char V_77 [ 64 ] ;
T_3 * V_78 ;
int V_20 ;
sprintf ( V_77 , L_79 , V_1 ) ;
V_78 = fopen ( V_77 , L_78 ) ;
if ( V_78 == NULL ) {
perror ( V_77 ) ;
exit ( 1 ) ;
}
fscanf ( V_78 , L_34 , & V_20 ) ;
fclose ( V_78 ) ;
return V_20 ;
}
int F_21 ( void (F_22)( int , int , int ) )
{
T_3 * V_79 ;
int V_80 ;
int V_3 ;
V_79 = fopen ( V_81 , L_78 ) ;
if ( V_79 == NULL ) {
perror ( V_81 ) ;
exit ( 1 ) ;
}
V_3 = fscanf ( V_79 , L_80 ) ;
if ( V_3 != 0 ) {
perror ( L_81 ) ;
exit ( 1 ) ;
}
for ( V_80 = 0 ; ; V_80 ++ ) {
int V_1 ;
V_3 = fscanf ( V_79 , L_82 , & V_1 ) ;
if ( V_3 != 1 )
break;
F_22 ( F_19 ( V_1 ) , F_20 ( V_1 ) , V_1 ) ;
}
fclose ( V_79 ) ;
return V_80 ;
}
void F_23 ( void )
{
printf ( L_83 ) ;
F_16 () ;
V_44 = F_21 ( F_18 ) ;
V_8 = 0 ;
printf ( L_84 , V_44 ) ;
}
void F_24 ( int V_19 , int V_20 , int V_1 ) { return; }
void F_25 ( void )
{
int V_82 ;
V_82 = F_21 ( F_24 ) ;
if ( V_82 != V_44 ) {
if ( V_67 )
printf ( L_85 ,
V_44 , V_82 ) ;
V_8 = 1 ;
}
}
void F_26 ()
{
V_83:
F_13 ( V_72 ) ;
F_27 ( & V_84 , (struct V_85 * ) NULL ) ;
while ( 1 ) {
F_25 () ;
if ( V_8 ) {
F_23 () ;
goto V_83;
}
F_28 ( V_86 ) ;
F_13 ( V_73 ) ;
F_27 ( & V_87 , (struct V_85 * ) NULL ) ;
F_10 ( V_73 , V_72 , V_74 ) ;
F_29 ( & V_87 , & V_84 , & V_34 ) ;
F_12 ( V_74 , V_37 ) ;
F_9 ( V_74 ) ;
if ( V_8 ) {
F_23 () ;
goto V_83;
}
F_28 ( V_86 ) ;
F_13 ( V_72 ) ;
F_27 ( & V_84 , (struct V_85 * ) NULL ) ;
F_10 ( V_72 , V_73 , V_74 ) ;
F_29 ( & V_84 , & V_87 , & V_34 ) ;
F_12 ( V_74 , V_37 ) ;
F_9 ( V_74 ) ;
}
}
void F_30 ()
{
struct V_88 V_89 ;
if ( V_88 ( L_86 , & V_89 ) ) {
fprintf ( V_9 , L_87 ) ;
fprintf ( V_9 , L_88 ) ;
exit ( - 5 ) ;
}
}
void F_31 ()
{
if ( F_32 () != 0 ) {
fprintf ( V_9 , L_89 ) ;
exit ( - 6 ) ;
}
}
int F_33 ( unsigned int V_90 , unsigned int V_91 )
{
if ( ! V_92 )
return 0 ;
if ( V_90 != 6 )
return 0 ;
switch ( V_91 ) {
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
int F_34 ( unsigned int V_90 , unsigned int V_91 )
{
if ( ! V_92 )
return 0 ;
switch ( V_91 ) {
case 0x2A :
case 0x2D :
return 1 ;
}
return 0 ;
}
double F_35 ( unsigned int V_90 , unsigned int V_91 )
{
if ( F_34 ( V_90 , V_91 ) )
return 100.00 ;
else
return 133.33 ;
}
void F_36 ()
{
unsigned int V_93 , V_94 , V_95 , V_96 , V_97 ;
unsigned int V_98 , V_90 , V_91 , V_99 ;
V_93 = V_94 = V_95 = V_96 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0));
if ( V_94 == 0x756e6547 && V_96 == 0x49656e69 && V_95 == 0x6c65746e )
V_92 = 1 ;
if ( V_67 )
fprintf ( V_9 , L_90 ,
( char * ) & V_94 , ( char * ) & V_96 , ( char * ) & V_95 ) ;
asm("cpuid" : "=a" (fms), "=c" (ecx), "=d" (edx) : "a" (1) : "ebx");
V_90 = ( V_98 >> 8 ) & 0xf ;
V_91 = ( V_98 >> 4 ) & 0xf ;
V_99 = V_98 & 0xf ;
if ( V_90 == 6 || V_90 == 0xf )
V_91 += ( ( V_98 >> 16 ) & 0xf ) << 4 ;
if ( V_67 )
fprintf ( V_9 , L_91 ,
V_97 , V_90 , V_91 , V_99 , V_90 , V_91 , V_99 ) ;
if ( ! ( V_96 & ( 1 << 5 ) ) ) {
fprintf ( V_9 , L_92 ) ;
exit ( 1 ) ;
}
V_94 = V_95 = V_96 = 0 ;
asm("cpuid" : "=a" (max_level), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000000));
if ( V_97 < 0x80000007 ) {
fprintf ( V_9 , L_93 , V_97 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x80000007));
V_100 = V_96 & ( 1 << 8 ) ;
if ( ! V_100 ) {
fprintf ( V_9 , L_94 ) ;
exit ( 1 ) ;
}
asm("cpuid" : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : "a" (0x6));
V_14 = V_95 & ( 1 << 0 ) ;
if ( ! V_14 ) {
fprintf ( V_9 , L_95 ) ;
exit ( 1 ) ;
}
V_64 = V_92 && V_100 ;
V_13 = V_92 ;
V_15 = F_34 ( V_90 , V_91 ) ;
V_66 = F_35 ( V_90 , V_91 ) ;
V_68 = F_33 ( V_90 , V_91 ) ;
}
void F_37 ()
{
fprintf ( V_9 , L_96 ,
V_50 ) ;
exit ( 1 ) ;
}
int F_38 ( const struct V_101 * V_102 )
{
if ( isdigit ( V_102 -> V_103 [ 0 ] ) )
return 1 ;
else
return 0 ;
}
int F_39 ( int V_104 )
{
return 0 ;
}
void F_40 ()
{
F_36 () ;
F_30 () ;
F_31 () ;
V_44 = F_21 ( F_18 ) ;
if ( V_67 )
F_14 () ;
}
int F_41 ( char * * V_105 )
{
int V_3 ;
T_4 V_106 ;
F_13 ( V_72 ) ;
F_27 ( & V_84 , (struct V_85 * ) NULL ) ;
V_106 = F_42 () ;
if ( ! V_106 ) {
F_43 ( V_105 [ 0 ] , V_105 ) ;
} else {
int V_107 ;
if ( V_106 == - 1 ) {
perror ( L_97 ) ;
exit ( 1 ) ;
}
signal ( V_108 , V_109 ) ;
signal ( V_110 , V_109 ) ;
if ( F_44 ( V_106 , & V_107 , 0 ) == - 1 ) {
perror ( L_98 ) ;
exit ( 1 ) ;
}
}
F_13 ( V_73 ) ;
F_27 ( & V_87 , (struct V_85 * ) NULL ) ;
V_3 = F_10 ( V_73 , V_72 , V_74 ) ;
F_29 ( & V_87 , & V_84 , & V_34 ) ;
F_12 ( V_74 , V_37 ) ;
if ( ! V_3 )
F_9 ( V_74 ) ;
fprintf ( V_9 , L_99 , V_34 . V_35 + V_34 . V_36 / 1000000.0 ) ;
return 0 ;
}
void F_45 ( int V_111 , char * * V_105 )
{
int V_112 ;
V_50 = V_105 [ 0 ] ;
while ( ( V_112 = F_46 ( V_111 , V_105 , L_100 ) ) != - 1 ) {
switch ( V_112 ) {
case 'v' :
V_67 ++ ;
break;
case 'i' :
V_86 = atoi ( V_113 ) ;
break;
case 'M' :
sscanf ( V_113 , L_101 , & V_16 ) ;
if ( V_67 > 1 )
fprintf ( V_9 , L_102 , V_16 ) ;
break;
default:
F_37 () ;
}
}
}
int main ( int V_111 , char * * V_105 )
{
F_45 ( V_111 , V_105 ) ;
if ( V_67 > 1 )
fprintf ( V_9 , L_103
L_104 ) ;
if ( V_67 > 1 )
fprintf ( V_9 , L_105 ) ;
F_40 () ;
if ( V_111 - V_114 )
return F_41 ( V_105 + V_114 ) ;
else
F_26 () ;
return 0 ;
}
