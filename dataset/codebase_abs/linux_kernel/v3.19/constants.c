static bool F_1 ( int V_1 , int V_2 ,
const char * * V_3 , const char * * V_4 )
{
struct V_5 * V_6 ;
const struct V_7 * V_8 = NULL ;
int V_9 , V_10 ;
* V_3 = NULL ;
if ( V_1 >= V_11 )
return false ;
if ( V_1 < F_2 ( V_12 ) )
* V_3 = V_12 [ V_1 ] ;
for ( V_6 = V_13 ; V_6 -> V_8 ; ++ V_6 ) {
if ( V_6 -> V_1 == V_1 ) {
V_8 = V_6 -> V_8 ;
V_9 = V_6 -> V_9 ;
break;
}
}
if ( ! V_8 )
return false ;
for ( V_10 = 0 ; V_10 < V_9 ; ++ V_10 , ++ V_8 ) {
if ( V_2 == V_8 -> V_14 )
break;
}
if ( V_10 < V_9 )
* V_4 = V_8 -> V_15 ;
return true ;
}
static void F_3 ( const unsigned char * V_16 , T_1 V_17 )
{
int V_18 , V_19 ;
const char * V_3 = NULL , * V_4 = NULL ;
V_19 = V_16 [ 0 ] ;
if ( V_19 == V_20 ) {
if ( V_17 < 10 ) {
F_4 ( L_1 ,
V_17 ) ;
return;
}
V_18 = ( V_16 [ 8 ] << 8 ) + V_16 [ 9 ] ;
} else
V_18 = V_16 [ 1 ] & 0x1f ;
if ( ! F_1 ( V_19 , V_18 , & V_3 , & V_4 ) ) {
if ( V_3 )
F_4 ( L_2 , V_3 ) ;
else if ( V_19 >= V_11 )
F_4 ( L_3 , V_19 ) ;
else if ( V_19 >= 0x60 && V_19 < 0x7e )
F_4 ( L_4 , V_19 ) ;
else
F_4 ( L_5 , V_19 ) ;
} else {
if ( V_4 )
F_4 ( L_2 , V_4 ) ;
else if ( V_3 )
F_4 ( L_6 , V_3 , V_18 ) ;
else
F_4 ( L_7 , V_19 , V_18 ) ;
}
}
void F_5 ( const unsigned char * V_21 , T_1 V_17 )
{
int V_10 , V_22 ;
F_3 ( V_21 , V_17 ) ;
V_22 = F_6 ( V_21 ) ;
if ( V_17 < V_22 )
V_22 = V_17 ;
for ( V_10 = 0 ; V_10 < V_22 ; ++ V_10 )
F_4 ( L_8 , V_21 [ V_10 ] ) ;
F_4 ( L_9 ) ;
}
void F_7 ( struct V_23 * V_24 )
{
int V_10 ;
if ( V_24 -> V_25 == NULL )
return;
F_8 ( V_26 , V_24 , L_10 ) ;
F_3 ( V_24 -> V_25 , V_24 -> V_27 ) ;
F_4 ( L_11 ) ;
for ( V_10 = 0 ; V_10 < V_24 -> V_27 ; ++ V_10 )
F_4 ( L_8 , V_24 -> V_25 [ V_10 ] ) ;
F_4 ( L_9 ) ;
}
const char *
F_9 ( unsigned char V_28 ) {
#ifdef F_10
if ( V_28 <= 0xE )
return V_29 [ V_28 ] ;
#endif
return NULL ;
}
const char *
F_11 ( unsigned char V_30 , unsigned char V_31 , const char * * V_32 )
{
#ifdef F_10
int V_33 ;
unsigned short V_34 = ( ( V_30 << 8 ) | V_31 ) ;
* V_32 = NULL ;
for ( V_33 = 0 ; V_35 [ V_33 ] . V_36 ; V_33 ++ )
if ( V_35 [ V_33 ] . V_37 == V_34 )
return V_35 [ V_33 ] . V_36 ;
for ( V_33 = 0 ; V_38 [ V_33 ] . V_32 ; V_33 ++ ) {
if ( V_38 [ V_33 ] . V_39 == V_30 &&
V_31 >= V_38 [ V_33 ] . V_40 &&
V_31 <= V_38 [ V_33 ] . V_41 ) {
* V_32 = V_38 [ V_33 ] . V_32 ;
return V_38 [ V_33 ] . V_42 ;
}
}
#else
* V_32 = NULL ;
#endif
return NULL ;
}
void
F_12 ( const struct V_43 * V_44 , const char * V_15 ,
unsigned char V_30 , unsigned char V_31 )
{
const char * V_45 = NULL ;
const char * V_46 = F_11 ( V_30 , V_31 ,
& V_45 ) ;
if ( V_46 ) {
if ( V_45 )
F_13 ( V_26 , V_44 , V_15 ,
L_12 ,
V_46 , V_45 ,
V_31 ) ;
else
F_13 ( V_26 , V_44 , V_15 ,
L_13 , V_46 ) ;
} else {
F_13 ( V_26 , V_44 , V_15 ,
L_14 ,
V_30 >= 0x80 ? L_15 : L_16 , V_30 ,
V_31 >= 0x80 ? L_15 : L_16 , V_31 ) ;
}
}
void
F_14 ( const struct V_43 * V_44 , const char * V_15 ,
const struct V_47 * V_48 )
{
const char * V_49 ;
V_49 = F_9 ( V_48 -> V_50 ) ;
if ( V_49 )
F_13 ( V_26 , V_44 , V_15 ,
L_17 , V_49 ,
F_15 ( V_48 ) ?
L_18 : L_19 ,
V_48 -> V_51 >= 0x72 ?
L_20 : L_16 ) ;
else
F_13 ( V_26 , V_44 , V_15 ,
L_21 , V_48 -> V_50 ,
F_15 ( V_48 ) ?
L_18 : L_19 ,
V_48 -> V_51 >= 0x72 ?
L_20 : L_16 ) ;
}
void
F_16 ( const struct V_43 * V_44 , const char * V_15 ,
const struct V_47 * V_48 )
{
F_14 ( V_44 , V_15 , V_48 ) ;
F_12 ( V_44 , V_15 , V_48 -> V_30 , V_48 -> V_31 ) ;
}
static void
F_17 ( const unsigned char * V_52 , int V_53 )
{
int V_10 , V_54 ;
V_54 = ( V_53 < 32 ) ? V_53 : 32 ;
F_4 ( L_22 ) ;
for ( V_10 = 0 ; V_10 < V_54 ; ++ V_10 ) {
if ( 0 == ( V_10 % 16 ) ) {
F_4 ( L_9 ) ;
F_4 ( V_26 L_23 ) ;
}
F_4 ( L_24 , V_52 [ V_10 ] ) ;
}
F_4 ( L_9 ) ;
return;
}
void F_18 ( const struct V_43 * V_44 , const char * V_15 ,
const unsigned char * V_52 , int V_53 )
{
struct V_47 V_48 ;
if ( ! F_19 ( V_52 , V_53 , & V_48 ) ) {
F_17 ( V_52 , V_53 ) ;
return;
}
F_14 ( V_44 , V_15 , & V_48 ) ;
F_12 ( V_44 , V_15 , V_48 . V_30 , V_48 . V_31 ) ;
}
void F_20 ( const struct V_23 * V_24 )
{
struct V_55 * V_56 = V_24 -> V_57 -> V_58 ;
const char * V_59 = V_56 ? V_56 -> V_59 : NULL ;
F_18 ( V_24 -> V_60 , V_59 , V_24 -> V_52 ,
V_61 ) ;
}
const char * F_21 ( int V_62 )
{
const char * V_63 = NULL ;
#ifdef F_10
int V_64 = F_22 ( V_62 ) ;
if ( V_64 < F_2 ( V_65 ) )
V_63 = V_65 [ V_64 ] ;
#endif
return V_63 ;
}
const char * F_23 ( int V_62 )
{
const char * V_66 = NULL ;
#ifdef F_10
int V_67 = F_24 ( V_62 ) ;
if ( V_67 < F_2 ( V_68 ) )
V_66 = V_68 [ V_67 ] ;
#endif
return V_66 ;
}
const char * F_25 ( int V_62 )
{
#ifdef F_10
const struct V_7 * V_8 = V_69 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < F_2 ( V_69 ) ; ++ V_10 , ++ V_8 ) {
if ( V_62 == V_8 -> V_14 )
return V_8 -> V_15 ;
}
#endif
return NULL ;
}
void F_26 ( struct V_23 * V_24 , const char * V_70 , int V_71 )
{
const char * V_72 = F_25 ( V_71 ) ;
const char * V_63 = F_21 ( V_24 -> V_62 ) ;
const char * V_66 = F_23 ( V_24 -> V_62 ) ;
if ( V_63 || V_66 )
F_8 ( V_26 , V_24 ,
L_25 ,
V_70 ? V_70 : L_16 ,
V_72 ? V_72 : L_26 ,
V_63 ? V_63 : L_27 ,
V_66 ? V_66 : L_27 ) ;
else
F_8 ( V_26 , V_24 ,
L_28 ,
V_70 ? V_70 : L_16 ,
V_72 ? V_72 : L_26 ,
F_22 ( V_24 -> V_62 ) , F_24 ( V_24 -> V_62 ) ) ;
}
