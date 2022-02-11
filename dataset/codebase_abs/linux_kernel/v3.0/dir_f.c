static inline unsigned int F_1 ( unsigned char * V_1 , int V_2 )
{
unsigned int V_3 = 0 ;
switch ( V_2 ) {
case 4 : V_3 |= V_1 [ 3 ] << 24 ;
case 3 : V_3 |= V_1 [ 2 ] << 16 ;
case 2 : V_3 |= V_1 [ 1 ] << 8 ;
default: V_3 |= V_1 [ 0 ] ;
}
return V_3 ;
}
static inline void F_2 ( unsigned char * V_1 , int V_2 , unsigned int V_3 )
{
switch ( V_2 ) {
case 4 : V_1 [ 3 ] = V_3 >> 24 ;
case 3 : V_1 [ 2 ] = V_3 >> 16 ;
case 2 : V_1 [ 1 ] = V_3 >> 8 ;
default: V_1 [ 0 ] = V_3 ;
}
}
static inline int F_3 ( char * V_4 , char * V_5 , int V_6 )
{
char * V_7 = V_4 ;
while ( ( unsigned char ) * V_5 >= ' ' && V_6 -- ) {
if ( * V_5 == '/' )
* V_4 ++ = '.' ;
else
* V_4 ++ = * V_5 ;
V_5 ++ ;
}
return V_4 - V_7 ;
}
static T_1
F_4 ( const struct V_8 * V_9 )
{
struct V_10 * const * V_11 = V_9 -> V_11 ;
const int V_12 = V_9 -> V_13 -> V_14 ;
union { T_2 * V_15 ; T_1 * V_16 ; } V_5 , V_17 ;
T_3 V_18 = 0 ;
int V_19 = 5 - 26 ;
int V_20 = 0 ;
do {
V_19 += 26 ;
do {
V_18 = F_5 ( F_6 ( V_20 ) ) ^ F_7 ( V_18 ) ;
V_20 += sizeof( T_3 ) ;
} while ( V_20 < ( V_19 & ~ 3 ) );
} while ( F_8 ( V_19 ) != 0 );
if ( V_20 != V_19 ) {
V_5 . V_16 = F_9 ( V_11 , V_20 ) ;
V_17 . V_16 = V_5 . V_16 + V_19 - V_20 ;
do {
V_18 = * V_5 . V_16 ++ ^ F_7 ( V_18 ) ;
} while ( V_5 . V_16 < V_17 . V_16 );
}
V_5 . V_16 = F_9 ( V_11 , 2008 ) ;
V_17 . V_16 = V_5 . V_16 + 36 ;
do {
T_2 V_21 = * V_5 . V_15 ++ ;
V_18 = F_5 ( V_21 ) ^ F_7 ( V_18 ) ;
} while ( V_5 . V_15 < V_17 . V_15 );
return ( V_18 ^ ( V_18 >> 8 ) ^ ( V_18 >> 16 ) ^ ( V_18 >> 24 ) ) & 0xff ;
}
static int
F_10 ( struct V_22 * V_13 , unsigned long V_23 ,
unsigned int V_24 , struct V_8 * V_9 )
{
const unsigned int V_12 = V_13 -> V_14 ;
int V_25 = 0 ;
if ( V_24 & 2047 )
goto V_26;
V_24 >>= V_12 ;
V_9 -> V_27 = 0 ;
V_9 -> V_13 = V_13 ;
for ( V_25 = 0 ; V_25 < V_24 ; V_25 ++ ) {
int V_28 ;
V_28 = F_11 ( V_13 , V_23 , V_25 ) ;
if ( ! V_28 ) {
F_12 ( V_13 , L_1 ,
V_23 , V_25 ) ;
goto V_29;
}
V_9 -> V_11 [ V_25 ] = F_13 ( V_13 , V_28 ) ;
if ( ! V_9 -> V_11 [ V_25 ] )
goto V_29;
}
memcpy ( & V_9 -> V_30 , F_9 ( V_9 -> V_11 , 0 ) , sizeof( V_9 -> V_30 ) ) ;
memcpy ( & V_9 -> V_31 , F_9 ( V_9 -> V_11 , 2007 ) , sizeof( V_9 -> V_31 ) ) ;
if ( V_9 -> V_30 . V_32 != V_9 -> V_31 . V_33 . V_34 ||
memcmp ( & V_9 -> V_30 . V_35 , & V_9 -> V_31 . V_33 . V_36 , 4 ) )
goto V_26;
if ( memcmp ( & V_9 -> V_30 . V_35 , L_2 , 4 ) &&
memcmp ( & V_9 -> V_30 . V_35 , L_3 , 4 ) )
goto V_26;
if ( F_4 ( V_9 ) != V_9 -> V_31 . V_33 . V_37 )
goto V_26;
V_9 -> V_27 = V_25 ;
return 0 ;
V_26:
F_12 ( V_13 , L_4 ,
V_23 ) ;
V_29:
for ( V_25 -= 1 ; V_25 >= 0 ; V_25 -= 1 )
F_14 ( V_9 -> V_11 [ V_25 ] ) ;
V_9 -> V_13 = NULL ;
return - V_38 ;
}
static inline void
F_15 ( struct V_8 * V_9 , struct V_39 * V_40 ,
struct V_41 * V_42 )
{
V_40 -> V_43 = F_3 ( V_40 -> V_44 , V_42 -> V_45 , V_46 ) ;
V_40 -> V_47 = F_1 ( V_42 -> V_48 , 3 ) ;
V_40 -> V_49 = F_1 ( V_42 -> V_50 , 4 ) ;
V_40 -> V_51 = F_1 ( V_42 -> V_52 , 4 ) ;
V_40 -> V_24 = F_1 ( V_42 -> V_53 , 4 ) ;
V_40 -> V_54 = V_42 -> V_55 ;
V_40 -> V_56 = - 1 ;
if ( ( 0 == ( V_40 -> V_54 & V_57 ) ) &&
( 0xfff00000 == ( 0xfff00000 & V_40 -> V_49 ) ) ) {
V_40 -> V_56 = ( V_58 ) ( ( 0x000fff00 & V_40 -> V_49 ) >> 8 ) ;
if ( F_16 ( V_9 -> V_13 ) -> V_59 )
V_40 -> V_43 +=
F_17 (
& V_40 -> V_44 [ V_40 -> V_43 ] ,
V_40 -> V_56 ) ;
}
}
static inline void
F_18 ( struct V_41 * V_42 , struct V_39 * V_40 )
{
F_2 ( V_42 -> V_48 , 3 , V_40 -> V_47 ) ;
F_2 ( V_42 -> V_50 , 4 , V_40 -> V_49 ) ;
F_2 ( V_42 -> V_52 , 4 , V_40 -> V_51 ) ;
F_2 ( V_42 -> V_53 , 4 , V_40 -> V_24 ) ;
V_42 -> V_55 = V_40 -> V_54 ;
}
static int
F_19 ( struct V_8 * V_9 , int V_60 , struct V_39 * V_40 )
{
struct V_22 * V_13 = V_9 -> V_13 ;
struct V_41 V_42 ;
int V_61 , V_62 , V_63 ;
V_62 = V_60 >> V_13 -> V_14 ;
if ( V_62 > V_9 -> V_27 )
return - V_64 ;
V_63 = V_60 & ( V_13 -> V_65 - 1 ) ;
V_61 = V_13 -> V_65 - V_63 ;
if ( V_61 > 26 )
V_61 = 26 ;
memcpy ( & V_42 , V_9 -> V_11 [ V_62 ] -> V_66 + V_63 , V_61 ) ;
if ( V_61 != 26 )
memcpy ( ( ( char * ) & V_42 ) + V_61 , V_9 -> V_11 [ V_62 + 1 ] -> V_66 ,
26 - V_61 ) ;
if ( ! V_42 . V_45 [ 0 ] )
return - V_67 ;
F_15 ( V_9 , V_40 , & V_42 ) ;
return 0 ;
}
static int
F_20 ( struct V_8 * V_9 , int V_60 , struct V_39 * V_40 )
{
struct V_22 * V_13 = V_9 -> V_13 ;
struct V_41 V_42 ;
int V_61 , V_62 , V_63 ;
V_62 = V_60 >> V_13 -> V_14 ;
if ( V_62 > V_9 -> V_27 )
return - V_64 ;
V_63 = V_60 & ( V_13 -> V_65 - 1 ) ;
V_61 = V_13 -> V_65 - V_63 ;
if ( V_61 > 26 )
V_61 = 26 ;
memcpy ( & V_42 , V_9 -> V_11 [ V_62 ] -> V_66 + V_63 , V_61 ) ;
if ( V_61 != 26 )
memcpy ( ( ( char * ) & V_42 ) + V_61 , V_9 -> V_11 [ V_62 + 1 ] -> V_66 ,
26 - V_61 ) ;
F_18 ( & V_42 , V_40 ) ;
memcpy ( V_9 -> V_11 [ V_62 ] -> V_66 + V_63 , & V_42 , V_61 ) ;
if ( V_61 != 26 )
memcpy ( V_9 -> V_11 [ V_62 + 1 ] -> V_66 , ( ( char * ) & V_42 ) + V_61 ,
26 - V_61 ) ;
return 0 ;
}
static int
F_21 ( struct V_8 * V_9 , unsigned long V_23 )
{
int V_60 , V_68 ;
V_68 = - V_67 ;
for ( V_60 = 5 ; V_60 < V_69 * 26 + 5 ; V_60 += 26 ) {
struct V_39 V_40 ;
if ( ! F_19 ( V_9 , V_60 , & V_40 ) )
break;
if ( V_40 . V_47 == V_23 ) {
V_68 = V_60 ;
break;
}
}
return V_68 ;
}
static int
F_22 ( struct V_22 * V_13 , unsigned int V_70 , unsigned int V_71 , struct V_8 * V_9 )
{
int V_68 ;
if ( V_71 != V_72 )
return - V_38 ;
V_68 = F_10 ( V_13 , V_70 , V_71 , V_9 ) ;
if ( V_68 )
F_12 ( V_13 , L_5 ) ;
else
V_9 -> V_73 = F_1 ( V_9 -> V_31 . V_33 . V_74 , 3 ) ;
return V_68 ;
}
static int
F_23 ( struct V_8 * V_9 , unsigned int V_75 )
{
if ( V_75 >= V_69 )
return - V_67 ;
V_9 -> V_60 = 5 + V_75 * 26 ;
return 0 ;
}
static int
F_24 ( struct V_8 * V_9 , struct V_39 * V_40 )
{
unsigned int V_68 ;
V_68 = F_19 ( V_9 , V_9 -> V_60 , V_40 ) ;
if ( V_68 == 0 )
V_9 -> V_60 += 26 ;
return V_68 ;
}
static int
F_25 ( struct V_8 * V_9 , struct V_39 * V_40 )
{
struct V_22 * V_13 = V_9 -> V_13 ;
int V_68 , V_20 ;
V_68 = F_21 ( V_9 , V_40 -> V_47 ) ;
if ( V_68 < 0 ) {
F_12 ( V_9 -> V_13 , L_6 ) ;
goto V_76;
}
F_20 ( V_9 , V_68 , V_40 ) ;
V_9 -> V_11 [ 0 ] -> V_66 [ 0 ] += 1 ;
V_9 -> V_11 [ V_9 -> V_27 - 1 ] -> V_66 [ V_13 -> V_65 - 6 ] += 1 ;
V_68 = F_4 ( V_9 ) ;
V_9 -> V_11 [ V_9 -> V_27 - 1 ] -> V_66 [ V_13 -> V_65 - 1 ] = V_68 ;
#if 1
{
const unsigned int V_12 = V_13 -> V_14 ;
memcpy ( & V_9 -> V_30 , F_9 ( V_9 -> V_11 , 0 ) , sizeof( V_9 -> V_30 ) ) ;
memcpy ( & V_9 -> V_31 , F_9 ( V_9 -> V_11 , 2007 ) , sizeof( V_9 -> V_31 ) ) ;
if ( V_9 -> V_30 . V_32 != V_9 -> V_31 . V_33 . V_34 ||
memcmp ( & V_9 -> V_30 . V_35 , & V_9 -> V_31 . V_33 . V_36 , 4 ) )
goto V_26;
if ( memcmp ( & V_9 -> V_30 . V_35 , L_2 , 4 ) &&
memcmp ( & V_9 -> V_30 . V_35 , L_3 , 4 ) )
goto V_26;
if ( F_4 ( V_9 ) != V_9 -> V_31 . V_33 . V_37 )
goto V_26;
}
#endif
for ( V_20 = V_9 -> V_27 - 1 ; V_20 >= 0 ; V_20 -- )
F_26 ( V_9 -> V_11 [ V_20 ] ) ;
V_68 = 0 ;
V_76:
return V_68 ;
#if 1
V_26:
F_12 ( V_9 -> V_13 , L_7 ) ;
return - V_38 ;
#endif
}
static int
F_27 ( struct V_8 * V_9 )
{
int V_77 = 0 ;
int V_20 ;
for ( V_20 = V_9 -> V_27 - 1 ; V_20 >= 0 ; V_20 -- ) {
struct V_10 * V_11 = V_9 -> V_11 [ V_20 ] ;
F_28 ( V_11 ) ;
if ( F_29 ( V_11 ) && ! F_30 ( V_11 ) )
V_77 = - V_38 ;
}
return V_77 ;
}
static void
F_31 ( struct V_8 * V_9 )
{
int V_20 ;
for ( V_20 = V_9 -> V_27 - 1 ; V_20 >= 0 ; V_20 -- ) {
F_14 ( V_9 -> V_11 [ V_20 ] ) ;
V_9 -> V_11 [ V_20 ] = NULL ;
}
V_9 -> V_27 = 0 ;
V_9 -> V_13 = NULL ;
}
