static int F_1 ( int V_1 )
{
void * V_2 ;
int V_3 ;
V_4 = F_2 () ;
V_3 = V_4 * ( V_5 + 1 ) ;
V_2 = F_3 ( NULL , V_3 , V_6 | V_7 , V_8 , V_1 , 0 ) ;
if ( V_2 == V_9 ) {
printf ( L_1 ) ;
return - 1 ;
}
V_10 = V_2 ;
return 0 ;
}
static int F_4 ( int V_1 )
{
struct V_11 V_12 = { . V_1 = V_1 , . V_13 = V_14 } ;
return F_5 ( & V_12 , 1 , 1000 ) ;
}
static void F_6 ( T_1 V_15 )
{
T_2 V_16 = V_10 -> V_16 ;
T_2 V_17 = V_10 -> V_17 ;
T_2 V_18 = V_5 * V_4 ;
void * V_2 , * V_19 , * V_20 ;
char V_21 [ 256 ] ;
asm volatile("" ::: "memory");
if ( V_17 == V_16 )
return;
V_2 = ( ( char * ) V_10 ) + V_4 ;
V_19 = V_2 + V_16 % V_18 ;
V_20 = V_2 + V_17 % V_18 ;
while ( V_19 != V_20 ) {
struct V_22 * V_23 ;
V_23 = V_19 ;
if ( V_19 + V_23 -> V_10 . V_24 > V_2 + V_18 ) {
long V_25 = V_2 + V_18 - V_19 ;
assert ( V_25 < V_23 -> V_10 . V_24 ) ;
memcpy ( V_21 , V_19 , V_25 ) ;
memcpy ( V_21 + V_25 , V_2 , V_23 -> V_10 . V_24 - V_25 ) ;
V_23 = ( void * ) V_21 ;
V_19 = V_2 + V_23 -> V_10 . V_24 - V_25 ;
} else if ( V_19 + V_23 -> V_10 . V_24 == V_2 + V_18 ) {
V_19 = V_2 ;
} else {
V_19 += V_23 -> V_10 . V_24 ;
}
if ( V_23 -> V_10 . type == V_26 ) {
V_15 ( V_23 -> V_27 , V_23 -> V_24 ) ;
} else if ( V_23 -> V_10 . type == V_28 ) {
struct {
struct V_29 V_10 ;
T_2 V_30 ;
T_2 V_31 ;
} * V_31 = ( void * ) V_23 ;
printf ( L_2 , V_31 -> V_31 ) ;
} else {
printf ( L_3 ,
V_23 -> V_10 . type , V_23 -> V_10 . V_24 ) ;
}
}
F_7 () ;
V_10 -> V_16 = V_17 ;
}
static T_2 F_8 ( void )
{
struct V_32 V_33 ;
F_9 ( V_34 , & V_33 ) ;
return V_33 . V_35 * 1000000000ull + V_33 . V_36 ;
}
static void F_10 ( void * V_27 , int V_24 )
{
static T_2 V_37 ;
struct {
T_2 V_38 ;
T_2 V_39 ;
} * V_23 = V_27 ;
if ( V_23 -> V_39 != 0x12345678 ) {
printf ( L_4 ,
V_23 -> V_38 , V_23 -> V_39 , V_24 ) ;
F_11 ( 0 , V_40 ) ;
}
V_37 ++ ;
if ( V_37 == V_41 ) {
printf ( L_5 ,
V_41 * 1000000000ll / ( F_8 () - V_42 ) ) ;
F_11 ( 0 , V_40 ) ;
}
}
static void F_12 ( void )
{
struct V_43 V_44 = {
. V_45 = V_46 ,
. type = V_47 ,
. V_48 = V_49 ,
} ;
int V_50 = 0 ;
V_51 = F_13 ( & V_44 , - 1 , 0 , - 1 , 0 ) ;
assert ( V_51 >= 0 ) ;
assert ( F_14 ( V_52 [ 0 ] , & V_50 , & V_51 , V_53 ) == 0 ) ;
F_15 ( V_51 , V_54 , 0 ) ;
}
int main ( int V_55 , char * * V_56 )
{
char V_57 [ 256 ] ;
T_3 * V_58 ;
snprintf ( V_57 , sizeof( V_57 ) , L_6 , V_56 [ 0 ] ) ;
if ( F_16 ( V_57 ) ) {
printf ( L_7 , V_59 ) ;
return 1 ;
}
F_12 () ;
if ( F_1 ( V_51 ) < 0 )
return 1 ;
V_58 = F_17 ( L_8 , L_9 ) ;
( void ) V_58 ;
V_42 = F_8 () ;
for (; ; ) {
F_4 ( V_51 ) ;
F_6 ( F_10 ) ;
}
return 0 ;
}
