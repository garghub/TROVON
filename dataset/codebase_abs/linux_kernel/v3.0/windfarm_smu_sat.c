struct V_1 * F_1 ( unsigned int V_2 , int V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
unsigned int V_8 , V_9 ;
T_1 * V_10 ;
T_1 V_11 [ 4 ] ;
if ( V_2 > 1 || ( V_6 = V_12 [ V_2 ] ) == NULL )
return NULL ;
V_7 = F_2 ( V_6 -> V_13 , 8 , V_3 << 8 ) ;
if ( V_7 ) {
F_3 ( V_14 L_1 , V_7 ) ;
return NULL ;
}
V_7 = F_4 ( V_6 -> V_13 , 9 ) ;
if ( V_7 < 0 ) {
F_3 ( V_14 L_2 ) ;
return NULL ;
}
V_9 = V_7 ;
if ( V_9 == 0 ) {
F_3 ( V_14 L_3 , V_3 ) ;
return NULL ;
}
V_9 = F_5 ( V_9 ) ;
V_9 = ( V_9 + 3 ) & ~ 3 ;
V_10 = F_6 ( V_9 , V_15 ) ;
if ( V_10 == NULL )
return NULL ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 += 4 ) {
V_7 = F_7 ( V_6 -> V_13 , 0xa , 4 , V_11 ) ;
if ( V_7 < 0 ) {
F_3 ( V_14 L_4 ,
V_7 ) ;
goto V_16;
}
V_10 [ V_8 ] = V_11 [ 1 ] ;
V_10 [ V_8 + 1 ] = V_11 [ 0 ] ;
V_10 [ V_8 + 2 ] = V_11 [ 3 ] ;
V_10 [ V_8 + 3 ] = V_11 [ 2 ] ;
}
#ifdef F_8
F_9 ( V_17 L_5 , V_2 , V_3 ) ;
for ( V_8 = 0 ; V_8 < V_9 ; ++ V_8 )
F_9 ( L_6 , V_10 [ V_8 ] ) ;
F_9 ( L_7 ) ;
#endif
if ( V_4 )
* V_4 = V_9 ;
return (struct V_1 * ) V_10 ;
V_16:
F_10 ( V_10 ) ;
return NULL ;
}
static int F_11 ( struct V_5 * V_6 )
{
int V_7 ;
V_7 = F_7 ( V_6 -> V_13 , 0x3f , 16 , V_6 -> V_18 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 -> V_19 = V_20 ;
#ifdef F_12
{
int V_8 ;
F_9 ( V_17 L_8 ) ;
for ( V_8 = 0 ; V_8 < 16 ; ++ V_8 )
F_9 ( L_9 , V_6 -> V_18 [ V_8 ] ) ;
F_9 ( L_7 ) ;
}
#endif
return 0 ;
}
static int F_13 ( struct V_21 * V_22 , T_2 * V_23 )
{
struct V_24 * V_25 = F_14 ( V_22 ) ;
struct V_5 * V_6 = V_25 -> V_6 ;
int V_8 , V_7 ;
T_2 V_26 ;
if ( V_6 -> V_13 == NULL )
return - V_27 ;
F_15 ( & V_6 -> V_28 ) ;
if ( F_16 ( V_20 , ( V_6 -> V_19 + V_29 ) ) ) {
V_7 = F_11 ( V_6 ) ;
if ( V_7 )
goto V_16;
}
V_8 = V_25 -> V_30 * 2 ;
V_26 = ( ( V_6 -> V_18 [ V_8 ] << 8 ) + V_6 -> V_18 [ V_8 + 1 ] ) << V_25 -> V_31 ;
if ( V_25 -> V_32 >= 0 ) {
V_8 = V_25 -> V_32 * 2 ;
V_26 = ( V_26 * ( ( V_6 -> V_18 [ V_8 ] << 8 ) + V_6 -> V_18 [ V_8 + 1 ] ) ) >> 4 ;
}
* V_23 = V_26 ;
V_7 = 0 ;
V_16:
F_17 ( & V_6 -> V_28 ) ;
return V_7 ;
}
static void F_18 ( struct V_21 * V_22 )
{
struct V_24 * V_25 = F_14 ( V_22 ) ;
struct V_5 * V_6 = V_25 -> V_6 ;
if ( F_19 ( & V_6 -> V_33 ) ) {
if ( V_6 -> V_34 >= 0 )
V_12 [ V_6 -> V_34 ] = NULL ;
F_10 ( V_6 ) ;
}
F_10 ( V_25 ) ;
}
static void F_20 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
struct V_39 V_40 ;
struct V_41 * V_42 ;
const T_3 * V_43 ;
T_1 V_44 ;
V_43 = F_21 ( V_38 , L_10 , NULL ) ;
if ( V_43 == NULL )
return;
V_44 = * V_43 ;
F_9 ( V_17 L_11 , V_44 ) ;
memset ( & V_40 , 0 , sizeof( struct V_39 ) ) ;
V_40 . V_44 = ( V_44 >> 1 ) & 0x7f ;
V_40 . V_45 = V_38 ;
F_22 ( V_40 . type , L_12 , V_46 ) ;
V_42 = F_23 ( V_36 , & V_40 ) ;
if ( V_42 == NULL ) {
F_3 ( V_14 L_13 ) ;
return;
}
F_24 ( & V_42 -> V_47 , & V_48 . V_49 ) ;
}
static int F_25 ( struct V_41 * V_42 ,
const struct V_50 * V_3 )
{
struct V_37 * V_38 = V_42 -> V_38 . V_45 ;
struct V_5 * V_6 ;
struct V_24 * V_25 ;
const T_3 * V_43 ;
const char * V_51 , * type ;
T_1 V_52 , V_53 ;
struct V_37 * V_54 ;
int V_31 , V_55 , V_30 ;
char * V_56 ;
int V_57 [ 2 ] , V_58 [ 2 ] ;
V_6 = F_26 ( sizeof( struct V_5 ) , V_15 ) ;
if ( V_6 == NULL )
return - V_59 ;
V_6 -> V_34 = - 1 ;
V_6 -> V_60 = F_27 ( V_38 ) ;
F_28 ( & V_6 -> V_33 , 0 ) ;
F_29 ( & V_6 -> V_28 ) ;
V_6 -> V_13 = V_42 ;
F_30 ( V_42 , V_6 ) ;
V_57 [ 0 ] = V_57 [ 1 ] = - 1 ;
V_58 [ 0 ] = V_58 [ 1 ] = - 1 ;
V_54 = NULL ;
while ( ( V_54 = F_31 ( V_38 , V_54 ) ) != NULL ) {
V_43 = F_21 ( V_54 , L_10 , NULL ) ;
type = F_21 ( V_54 , L_14 , NULL ) ;
V_51 = F_21 ( V_54 , L_15 , NULL ) ;
if ( V_43 == NULL || V_51 == NULL )
continue;
if ( * V_43 < 0x30 || * V_43 > 0x37 )
continue;
V_30 = * V_43 - 0x30 ;
if ( strncmp ( V_51 , L_16 , 4 ) != 0 )
continue;
V_52 = V_51 [ 4 ] - 'A' ;
V_53 = V_51 [ 5 ] - '0' ;
if ( V_52 > 1 || V_53 > 1 ) {
F_3 ( V_14 L_17
L_18 , V_51 , V_54 -> V_61 ) ;
continue;
}
V_55 = 2 * V_52 + V_53 ;
if ( V_6 -> V_34 < 0 )
V_6 -> V_34 = V_52 ;
else if ( V_6 -> V_34 != V_52 ) {
F_3 ( V_14 L_19
L_20 , V_51 ) ;
continue;
}
if ( strcmp ( type , L_21 ) == 0 ) {
V_56 = L_22 ;
V_31 = 4 ;
V_57 [ V_53 ] = V_30 ;
} else if ( strcmp ( type , L_23 ) == 0 ) {
V_56 = L_24 ;
V_31 = 8 ;
V_58 [ V_53 ] = V_30 ;
} else if ( strcmp ( type , L_25 ) == 0 ) {
V_56 = L_26 ;
V_31 = 10 ;
} else
continue;
V_25 = F_26 ( sizeof( struct V_24 ) + 16 , V_15 ) ;
if ( V_25 == NULL ) {
F_3 ( V_14 L_27
L_28 , V_56 , V_55 ) ;
continue;
}
V_25 -> V_30 = V_30 ;
V_25 -> V_32 = - 1 ;
V_25 -> V_31 = V_31 ;
V_25 -> V_6 = V_6 ;
F_32 ( & V_6 -> V_33 ) ;
V_25 -> V_25 . V_62 = & V_63 ;
V_25 -> V_25 . V_56 = ( char * ) ( V_25 + 1 ) ;
snprintf ( V_25 -> V_25 . V_56 , 16 , L_29 , V_56 , V_55 ) ;
if ( F_33 ( & V_25 -> V_25 ) ) {
F_34 ( & V_6 -> V_33 ) ;
F_10 ( V_25 ) ;
}
}
for ( V_53 = 0 ; V_53 < 2 ; ++ V_53 ) {
if ( V_57 [ V_53 ] < 0 || V_58 [ V_53 ] < 0 )
continue;
V_55 = 2 * V_6 -> V_34 + V_53 ;
V_25 = F_26 ( sizeof( struct V_24 ) + 16 , V_15 ) ;
if ( V_25 == NULL ) {
F_3 ( V_14 L_30
L_31 , V_55 ) ;
continue;
}
V_25 -> V_30 = V_57 [ V_53 ] ;
V_25 -> V_32 = V_58 [ V_53 ] ;
V_25 -> V_31 = 0 ;
V_25 -> V_6 = V_6 ;
F_32 ( & V_6 -> V_33 ) ;
V_25 -> V_25 . V_62 = & V_63 ;
V_25 -> V_25 . V_56 = ( char * ) ( V_25 + 1 ) ;
snprintf ( V_25 -> V_25 . V_56 , 16 , L_32 , V_55 ) ;
if ( F_33 ( & V_25 -> V_25 ) ) {
F_34 ( & V_6 -> V_33 ) ;
F_10 ( V_25 ) ;
}
}
if ( V_6 -> V_34 >= 0 )
V_12 [ V_6 -> V_34 ] = V_6 ;
return 0 ;
}
static int F_35 ( struct V_35 * V_36 )
{
struct V_37 * V_64 , * V_38 = NULL ;
struct V_65 * V_66 ;
V_66 = F_36 ( V_36 ) ;
if ( V_66 == NULL )
return - V_27 ;
V_64 = F_37 ( V_66 ) ;
while ( ( V_38 = F_31 ( V_64 , V_38 ) ) != NULL )
if ( F_38 ( V_38 , L_33 ) )
F_20 ( V_36 , V_38 ) ;
return 0 ;
}
static int F_39 ( struct V_41 * V_42 )
{
struct V_5 * V_6 = F_40 ( V_42 ) ;
V_6 -> V_13 = NULL ;
return 0 ;
}
static int T_4 F_41 ( void )
{
return F_42 ( & V_48 ) ;
}
