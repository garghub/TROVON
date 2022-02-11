void F_1 ( T_1 * V_1 ,
const char * V_2 )
{
unsigned long V_3 ;
fprintf ( V_4 , L_1 , V_2 ) ;
while ( ( V_3 = F_2 () ) ) {
char V_5 [ 1024 ] ;
F_3 ( V_3 , V_5 , sizeof V_5 ) ;
fprintf ( V_4 , L_2 , V_3 , V_5 ) ;
}
}
T_1 * F_4 ( const char * V_6 ,
const char * V_7 )
{
T_1 * V_1 = malloc ( sizeof *V_1 ) ;
int V_8 ;
F_5 ( V_1 ) ;
V_1 -> V_9 = F_6 ( F_7 () ) ;
F_5 ( V_1 -> V_9 ) ;
V_8 = F_8 ( V_1 -> V_9 , V_6 ,
V_10 ) ;
F_5 ( V_8 > 0 ) ;
V_8 = F_9 ( V_1 -> V_9 , V_7 ,
V_10 ) ;
F_5 ( V_8 > 0 ) ;
V_1 -> V_11 = F_10 ( V_1 -> V_9 ) ;
F_5 ( V_1 -> V_11 ) ;
V_1 -> V_12 = F_11 ( F_12 () ) ;
V_1 -> V_13 = F_11 ( F_12 () ) ;
F_13 ( V_1 -> V_11 , V_1 -> V_12 , V_1 -> V_13 ) ;
F_14 ( V_1 -> V_11 ) ;
return V_1 ;
}
void F_15 ( T_1 * V_1 ,
const unsigned char * V_14 , int V_15 )
{
int V_8 = F_16 ( V_1 -> V_12 , V_14 , V_15 ) ;
assert ( V_8 == V_15 ) ;
fprintf ( V_4 , L_3 , V_8 ) ;
}
int F_17 ( T_1 * V_1 ,
unsigned char * V_14 , int V_15 )
{
int V_8 ;
if ( ! F_18 ( V_1 -> V_11 ) ) {
fprintf ( V_4 , L_4 ) ;
V_8 = F_19 ( V_1 -> V_11 ) ;
if ( V_8 == 0 )
fprintf ( V_4 , L_5 ) ;
if ( V_8 < 0 ) {
int V_16 ;
if ( ( V_16 =
F_20 ( V_1 -> V_11 , V_8 ) ) == V_17 ) {
fprintf ( V_4 , L_6 ) ;
return 0 ;
}
F_1 ( V_1 , L_7 ) ;
exit ( 7 ) ;
}
return 0 ;
}
V_8 = F_21 ( V_1 -> V_11 , V_14 , V_15 ) ;
if ( V_8 < 0 ) {
int V_16 = F_20 ( V_1 -> V_11 , V_8 ) ;
if ( V_16 == V_17 ) {
fprintf ( V_4 , L_8 ) ;
return 0 ;
}
F_1 ( V_1 , L_9 ) ;
exit ( 8 ) ;
}
fprintf ( V_4 , L_10 ,
V_8 ) ;
return V_8 ;
}
int F_22 ( T_1 * V_1 )
{
int V_8 = F_23 ( V_1 -> V_13 ) ;
if ( V_8 )
fprintf ( V_4 , L_11 ) ;
else
fprintf ( V_4 , L_12 ) ;
return V_8 ;
}
int F_24 ( T_1 * V_1 ,
unsigned char * V_14 , int V_15 )
{
int V_8 ;
V_8 = F_25 ( V_1 -> V_13 , V_14 , V_15 ) ;
fprintf ( V_4 , L_13 ,
V_8 ) ;
return V_8 ;
}
void F_26 ( T_1 * V_1 ,
const unsigned char * V_14 , int V_15 )
{
int V_8 = F_27 ( V_1 -> V_11 , V_14 , V_15 ) ;
assert ( V_8 == V_15 ) ;
fprintf ( V_4 , L_14 , V_8 ) ;
}
int F_28 ( int V_18 )
{
int V_19 ;
struct V_20 V_21 ;
struct V_20 V_22 ;
int V_23 = 1 ;
int V_24 ;
int V_25 ;
int V_26 ;
V_19 = F_29 ( V_27 , V_28 , V_29 ) ;
if ( V_19 < 0 ) {
perror ( L_15 ) ;
exit ( 1 ) ;
}
if ( F_30
( V_19 , V_30 , V_31 , ( char * ) & V_23 , sizeof V_23 ) < 0 ) {
perror ( L_16 ) ;
exit ( 2 ) ;
}
memset ( & V_21 , 0 , sizeof V_21 ) ;
V_21 . V_32 = V_27 ;
V_21 . V_33 = F_31 ( V_18 ) ;
V_24 = sizeof V_21 ;
if ( F_32 ( V_19 , (struct V_34 * ) & V_21 , V_24 ) < 0 ) {
perror ( L_17 ) ;
exit ( 3 ) ;
}
if ( F_33 ( V_19 , 512 ) < 0 ) {
perror ( L_18 ) ;
exit ( 4 ) ;
}
V_26 = sizeof V_22 ;
V_25 = F_34 ( V_19 , (struct V_34 * ) & V_22 , & V_26 ) ;
if ( V_25 < 0 ) {
perror ( L_19 ) ;
exit ( 5 ) ;
}
fprintf ( V_4 , L_20 , V_18 ) ;
return V_25 ;
}
int main ( int V_35 , char * * V_36 )
{
T_1 * V_1 ;
int V_18 ;
int V_25 ;
const char * V_6 ;
const char * V_7 ;
char V_37 [ 1 ] ;
int V_38 = 0 ;
if ( V_35 != 4 ) {
fprintf ( V_4 , L_21 , V_36 [ 0 ] ) ;
exit ( 6 ) ;
}
V_18 = atoi ( V_36 [ 1 ] ) ;
V_6 = V_36 [ 2 ] ;
V_7 = V_36 [ 3 ] ;
F_35 () ;
F_36 () ;
F_37 () ;
F_38 () ;
V_25 = F_28 ( V_18 ) ;
V_1 = F_4 ( V_6 , V_7 ) ;
for (; ; ) {
T_2 V_39 , V_40 ;
unsigned char V_5 [ 1024 ] ;
int V_8 ;
F_39 ( & V_39 ) ;
F_39 ( & V_40 ) ;
F_40 ( V_25 , & V_39 ) ;
if ( ! V_38 )
V_38 = F_17 ( V_1 , V_37 , 1 ) ;
if ( V_38 )
F_40 ( 1 , & V_40 ) ;
if ( F_22 ( V_1 ) )
F_40 ( V_25 , & V_40 ) ;
F_40 ( 0 , & V_39 ) ;
V_8 = F_41 ( V_25 + 1 , & V_39 , & V_40 , NULL , NULL ) ;
assert ( V_8 > 0 ) ;
if ( F_42 ( V_25 , & V_39 ) ) {
V_8 = F_43 ( V_25 , V_5 , sizeof V_5 ) ;
if ( V_8 == 0 ) {
fprintf ( V_4 , L_22 ) ;
exit ( 0 ) ;
}
assert ( V_8 > 0 ) ;
F_15 ( V_1 , V_5 , V_8 ) ;
}
if ( F_42 ( 1 , & V_40 ) ) {
assert ( V_38 == 1 ) ;
V_5 [ 0 ] = V_37 [ 0 ] ;
V_38 = 0 ;
V_8 = F_17 ( V_1 , V_5 + 1 ,
sizeof V_5 - 1 ) ;
if ( V_8 < 0 ) {
F_1 ( V_1 , L_23 ) ;
break;
}
assert ( V_8 >= 0 ) ;
++ V_8 ;
if ( V_8 > 0 ) {
int V_41 ;
V_41 = F_44 ( 1 , V_5 , V_8 ) ;
assert ( V_41 == V_8 ) ;
}
}
if ( F_42 ( V_25 , & V_40 ) ) {
int V_41 ;
V_8 = F_24 ( V_1 , V_5 , sizeof V_5 ) ;
assert ( V_8 > 0 ) ;
V_41 = F_44 ( V_25 , V_5 , V_8 ) ;
assert ( V_41 == V_8 ) ;
}
if ( F_42 ( 0 , & V_39 ) ) {
V_8 = F_43 ( 0 , V_5 , sizeof V_5 ) ;
if ( V_8 == 0 ) {
fprintf ( V_4 , L_24 ) ;
exit ( 0 ) ;
}
assert ( V_8 > 0 ) ;
F_26 ( V_1 , V_5 , V_8 ) ;
}
}
return 0 ;
}
