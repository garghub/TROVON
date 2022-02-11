static int F_1 ( int V_1 , int V_2 )
{
struct V_3 V_4 ;
int V_5 , V_6 = 0 , V_7 , V_8 = - 1 ;
char V_9 [ 4096 ] ;
struct V_10 * V_11 , * V_12 ;
struct {
struct V_13 V_14 ;
struct V_15 V_16 ;
char V_17 [ 64 ] ;
} V_18 ;
struct V_13 * V_14 ;
struct V_19 * V_20 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_21 = V_22 ;
V_5 = F_2 ( V_22 , V_23 , V_24 ) ;
if ( V_5 < 0 ) {
printf ( L_1 , strerror ( V_25 ) ) ;
return - 1 ;
}
if ( F_3 ( V_5 , (struct V_26 * ) & V_4 , sizeof( V_4 ) ) < 0 ) {
printf ( L_2 , strerror ( V_25 ) ) ;
goto V_27;
}
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_14 . V_28 = F_4 ( sizeof( struct V_15 ) ) ;
V_18 . V_14 . V_29 = V_30 | V_31 ;
V_18 . V_14 . V_32 = V_33 ;
V_18 . V_14 . V_34 = 0 ;
V_18 . V_14 . V_35 = ++ V_6 ;
V_18 . V_16 . V_36 = V_37 ;
V_18 . V_16 . V_38 = V_1 ;
V_11 = (struct V_10 * ) ( ( ( char * ) & V_18 )
+ F_5 ( V_18 . V_14 . V_28 ) ) ;
V_11 -> V_39 = V_40 | 43 ;
V_12 = (struct V_10 * ) ( ( char * ) V_11 + V_41 ) ;
V_12 -> V_39 = 1 ;
V_12 -> V_42 = V_41 + sizeof( int ) ;
memcpy ( ( char * ) V_12 + V_41 , & V_2 , sizeof( V_2 ) ) ;
V_11 -> V_42 = V_41 + V_12 -> V_42 ;
V_18 . V_14 . V_28 += F_6 ( V_11 -> V_42 ) ;
if ( F_7 ( V_5 , & V_18 , V_18 . V_14 . V_28 , 0 ) < 0 ) {
printf ( L_3 , strerror ( V_25 ) ) ;
goto V_27;
}
V_7 = F_8 ( V_5 , V_9 , sizeof( V_9 ) , 0 ) ;
if ( V_7 < 0 ) {
printf ( L_4 , strerror ( V_25 ) ) ;
goto V_27;
}
for ( V_14 = (struct V_13 * ) V_9 ; F_9 ( V_14 , V_7 ) ;
V_14 = F_10 ( V_14 , V_7 ) ) {
if ( V_14 -> V_34 != F_11 () ) {
printf ( L_5 ,
V_14 -> V_34 , F_11 () ) ;
goto V_27;
}
if ( V_14 -> V_35 != V_6 ) {
printf ( L_6 ,
V_14 -> V_35 , V_6 ) ;
goto V_27;
}
switch ( V_14 -> V_32 ) {
case V_43 :
V_20 = (struct V_19 * ) F_12 ( V_14 ) ;
if ( ! V_20 -> error )
continue;
printf ( L_7 , strerror ( - V_20 -> error ) ) ;
goto V_27;
case V_44 :
break;
}
}
V_8 = 0 ;
V_27:
F_13 ( V_5 ) ;
return V_8 ;
}
static void F_14 ( int V_45 )
{
F_1 ( V_1 , - 1 ) ;
exit ( 0 ) ;
}
static void F_15 ( int V_46 )
{
unsigned int V_47 = F_16 ( V_48 ) ;
const unsigned int V_49 = 256 ;
T_1 V_50 [ V_47 ] , V_51 [ V_49 ] [ V_47 ] ;
T_2 V_52 ;
int V_53 ;
memset ( V_51 , 0 , sizeof( V_51 ) ) ;
while ( 1 ) {
F_17 ( V_46 ) ;
for ( V_52 = 0 ; V_52 < V_49 ; V_52 ++ ) {
T_1 V_54 = 0 ;
assert ( F_18 ( V_55 [ 0 ] , & V_52 , V_50 ) == 0 ) ;
for ( V_53 = 0 ; V_53 < V_47 ; V_53 ++ )
V_54 += ( V_50 [ V_53 ] - V_51 [ V_52 ] [ V_53 ] ) ;
if ( V_54 )
printf ( L_8 ,
V_52 , V_54 / V_46 ) ;
memcpy ( V_51 [ V_52 ] , V_50 , sizeof( V_50 ) ) ;
}
}
}
int main ( int V_56 , char * * V_57 )
{
char V_58 [ 256 ] ;
snprintf ( V_58 , sizeof( V_58 ) , L_9 , V_57 [ 0 ] ) ;
if ( V_56 != 2 ) {
printf ( L_10 , V_57 [ 0 ] ) ;
return 1 ;
}
V_1 = strtoul ( V_57 [ 1 ] , NULL , 0 ) ;
if ( F_19 ( V_58 ) ) {
printf ( L_11 , V_59 ) ;
return 1 ;
}
if ( ! V_60 [ 0 ] ) {
printf ( L_12 , strerror ( V_25 ) ) ;
return 1 ;
}
signal ( V_61 , F_14 ) ;
if ( F_1 ( V_1 , V_60 [ 0 ] ) < 0 ) {
printf ( L_13 ) ;
return 1 ;
}
F_15 ( 2 ) ;
return 0 ;
}
