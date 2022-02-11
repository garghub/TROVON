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
static void F_18 ( struct V_33 * V_34 )
{
struct V_5 * V_6 = F_19 ( V_34 , struct V_5 , V_34 ) ;
if ( V_6 -> V_35 >= 0 )
V_12 [ V_6 -> V_35 ] = NULL ;
F_10 ( V_6 ) ;
}
static void F_20 ( struct V_21 * V_22 )
{
struct V_24 * V_25 = F_14 ( V_22 ) ;
struct V_5 * V_6 = V_25 -> V_6 ;
F_10 ( V_25 ) ;
F_21 ( & V_6 -> V_34 , F_18 ) ;
}
static int F_22 ( struct V_36 * V_37 ,
const struct V_38 * V_3 )
{
struct V_39 * V_40 = V_37 -> V_40 . V_41 ;
struct V_5 * V_6 ;
struct V_24 * V_25 ;
const T_3 * V_42 ;
const char * V_43 , * type ;
T_1 V_44 , V_45 ;
struct V_39 * V_46 ;
int V_31 , V_47 , V_30 ;
char * V_48 ;
int V_49 [ 2 ] , V_50 [ 2 ] ;
V_6 = F_23 ( sizeof( struct V_5 ) , V_15 ) ;
if ( V_6 == NULL )
return - V_51 ;
V_6 -> V_35 = - 1 ;
V_6 -> V_52 = F_24 ( V_40 ) ;
F_25 ( & V_6 -> V_34 ) ;
F_26 ( & V_6 -> V_28 ) ;
V_6 -> V_13 = V_37 ;
F_27 ( & V_6 -> V_53 ) ;
F_28 ( V_37 , V_6 ) ;
V_49 [ 0 ] = V_49 [ 1 ] = - 1 ;
V_50 [ 0 ] = V_50 [ 1 ] = - 1 ;
V_46 = NULL ;
while ( ( V_46 = F_29 ( V_40 , V_46 ) ) != NULL ) {
V_42 = F_30 ( V_46 , L_10 , NULL ) ;
type = F_30 ( V_46 , L_11 , NULL ) ;
V_43 = F_30 ( V_46 , L_12 , NULL ) ;
if ( V_42 == NULL || V_43 == NULL )
continue;
if ( * V_42 < 0x30 || * V_42 > 0x37 )
continue;
V_30 = * V_42 - 0x30 ;
if ( strncmp ( V_43 , L_13 , 4 ) != 0 )
continue;
V_44 = V_43 [ 4 ] - 'A' ;
V_45 = V_43 [ 5 ] - '0' ;
if ( V_44 > 1 || V_45 > 1 ) {
F_3 ( V_14 L_14
L_15 , V_43 , V_46 -> V_54 ) ;
continue;
}
V_47 = 2 * V_44 + V_45 ;
if ( V_6 -> V_35 < 0 )
V_6 -> V_35 = V_44 ;
else if ( V_6 -> V_35 != V_44 ) {
F_3 ( V_14 L_16
L_17 , V_43 ) ;
continue;
}
if ( strcmp ( type , L_18 ) == 0 ) {
V_48 = L_19 ;
V_31 = 4 ;
V_49 [ V_45 ] = V_30 ;
} else if ( strcmp ( type , L_20 ) == 0 ) {
V_48 = L_21 ;
V_31 = 8 ;
V_50 [ V_45 ] = V_30 ;
} else if ( strcmp ( type , L_22 ) == 0 ) {
V_48 = L_23 ;
V_31 = 10 ;
} else
continue;
V_25 = F_23 ( sizeof( struct V_24 ) + 16 , V_15 ) ;
if ( V_25 == NULL ) {
F_3 ( V_14 L_24
L_25 , V_48 , V_47 ) ;
continue;
}
V_25 -> V_30 = V_30 ;
V_25 -> V_32 = - 1 ;
V_25 -> V_31 = V_31 ;
V_25 -> V_6 = V_6 ;
V_25 -> V_25 . V_55 = & V_56 ;
V_25 -> V_25 . V_48 = ( char * ) ( V_25 + 1 ) ;
snprintf ( ( char * ) V_25 -> V_25 . V_48 , 16 , L_26 , V_48 , V_47 ) ;
if ( F_31 ( & V_25 -> V_25 ) )
F_10 ( V_25 ) ;
else {
F_32 ( & V_25 -> V_57 , & V_6 -> V_53 ) ;
F_33 ( & V_6 -> V_34 ) ;
}
}
for ( V_45 = 0 ; V_45 < 2 ; ++ V_45 ) {
if ( V_49 [ V_45 ] < 0 || V_50 [ V_45 ] < 0 )
continue;
V_47 = 2 * V_6 -> V_35 + V_45 ;
V_25 = F_23 ( sizeof( struct V_24 ) + 16 , V_15 ) ;
if ( V_25 == NULL ) {
F_3 ( V_14 L_27
L_28 , V_47 ) ;
continue;
}
V_25 -> V_30 = V_49 [ V_45 ] ;
V_25 -> V_32 = V_50 [ V_45 ] ;
V_25 -> V_31 = 0 ;
V_25 -> V_6 = V_6 ;
V_25 -> V_25 . V_55 = & V_56 ;
V_25 -> V_25 . V_48 = ( char * ) ( V_25 + 1 ) ;
snprintf ( ( char * ) V_25 -> V_25 . V_48 , 16 , L_29 , V_47 ) ;
if ( F_31 ( & V_25 -> V_25 ) )
F_10 ( V_25 ) ;
else {
F_32 ( & V_25 -> V_57 , & V_6 -> V_53 ) ;
F_33 ( & V_6 -> V_34 ) ;
}
}
if ( V_6 -> V_35 >= 0 )
V_12 [ V_6 -> V_35 ] = V_6 ;
return 0 ;
}
static int F_34 ( struct V_36 * V_37 )
{
struct V_5 * V_6 = F_35 ( V_37 ) ;
struct V_24 * V_25 ;
while( ! F_36 ( & V_6 -> V_53 ) ) {
V_25 = F_37 ( & V_6 -> V_53 ,
struct V_24 , V_57 ) ;
F_38 ( & V_25 -> V_57 ) ;
F_39 ( & V_25 -> V_25 ) ;
}
V_6 -> V_13 = NULL ;
F_28 ( V_37 , NULL ) ;
F_21 ( & V_6 -> V_34 , F_18 ) ;
return 0 ;
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_58 ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_58 ) ;
}
