static inline void F_1 ( T_1 V_1 )
{
F_2 ( V_1 , V_2 . V_3 ) ;
}
static inline void F_3 ( T_1 V_4 , T_1 V_5 )
{
F_2 ( V_4 , V_2 . V_3 + 0x80 + V_5 ) ;
}
static inline T_2 F_4 ( void )
{
return F_5 ( V_2 . V_3 + 0x04 ) ;
}
static inline T_2 F_6 ( T_1 V_5 )
{
return F_7 ( V_2 . V_3 + V_6 + V_5 ) ;
}
static inline T_1 F_8 ( T_1 V_5 )
{
return F_9 ( V_2 . V_3 + V_6 + V_5 ) ;
}
static inline int F_10 ( void )
{
T_1 V_7 = 0 ;
T_1 V_8 = 0 ;
V_7 = F_4 () ;
while ( V_7 & 1 ) {
F_11 ( 1 ) ;
V_7 = F_4 () ;
V_8 ++ ;
if ( V_8 > 100000 ) {
F_12 ( & V_2 . V_9 -> V_10 , L_1 ) ;
return - V_11 ;
}
}
if ( ( V_7 >> 1 ) & 1 )
return - V_12 ;
return 0 ;
}
static int F_13 ( T_3 * V_13 , T_2 * V_4 , T_1 V_14 , T_1 V_15 , T_1 V_16 )
{
int V_17 , V_18 , V_19 , V_20 ;
T_1 V_5 = 0 ;
int V_21 ;
T_2 V_22 [ V_23 ] = { } ;
T_1 * V_24 = ( T_1 * ) & V_22 ;
F_14 ( & V_25 ) ;
memset ( V_22 , 0 , sizeof( V_22 ) ) ;
if ( V_2 . V_9 == NULL ) {
F_15 ( & V_25 ) ;
return - V_26 ;
}
if ( V_27 != V_28 ) {
V_19 = 0 ;
V_20 = 0 ;
for ( V_17 = 0 ; V_17 < V_14 ; V_17 ++ ) {
V_22 [ V_19 ++ ] = V_13 [ V_17 ] ;
V_22 [ V_19 ++ ] = V_13 [ V_17 ] >> 8 ;
if ( V_16 != V_29 )
V_22 [ V_19 ++ ] = V_4 [ V_20 ++ ] ;
if ( V_16 == V_30 )
V_22 [ V_19 ++ ] = V_4 [ V_20 ++ ] ;
}
for ( V_17 = 0 ; V_17 < V_19 ; V_17 += 4 )
F_3 ( V_24 [ V_17 / 4 ] , V_17 ) ;
F_1 ( V_19 << 16 | V_16 << 12 | 0 << 8 | V_15 ) ;
} else {
for ( V_18 = 0 ; V_18 < V_14 ; V_18 ++ , V_5 += 2 ) {
V_22 [ V_5 ] = V_13 [ V_18 ] ;
V_22 [ V_5 + 1 ] = V_13 [ V_18 ] >> 8 ;
}
if ( V_16 == V_29 ) {
for ( V_18 = 0 , V_5 = 0 ; V_18 < V_14 ; V_18 ++ , V_5 += 4 )
F_3 ( V_24 [ V_18 ] , V_5 ) ;
F_1 ( ( V_14 * 2 ) << 16 | V_16 << 12 | 0 << 8 | V_15 ) ;
} else if ( V_16 == V_31 ) {
for ( V_18 = 0 ; V_18 < V_14 ; V_18 ++ , V_5 += 1 )
V_22 [ V_5 ] = V_4 [ V_18 ] ;
for ( V_18 = 0 , V_5 = 0 ; V_18 < V_14 ; V_18 ++ , V_5 += 4 )
F_3 ( V_24 [ V_18 ] , V_5 ) ;
F_1 ( ( V_14 * 3 ) << 16 | V_16 << 12 | 0 << 8 | V_15 ) ;
} else if ( V_16 == V_30 ) {
V_22 [ V_5 ] = V_4 [ 0 ] ;
V_22 [ V_5 + 1 ] = V_4 [ 1 ] ;
F_3 ( V_24 [ 0 ] , 0 ) ;
F_1 ( 4 << 16 | V_16 << 12 | 0 << 8 | V_15 ) ;
}
}
V_21 = F_10 () ;
if ( V_16 == V_29 ) {
F_16 ( V_22 , V_2 . V_3 + 0x90 , 16 ) ;
if ( V_27 != V_28 ) {
for ( V_18 = 0 , V_5 = 2 ; V_18 < V_14 ; V_18 ++ , V_5 += 3 )
V_4 [ V_18 ] = F_6 ( V_5 ) ;
} else {
for ( V_18 = 0 ; V_18 < V_14 ; V_18 ++ )
V_4 [ V_18 ] = F_6 ( V_18 ) ;
}
}
F_15 ( & V_25 ) ;
return V_21 ;
}
int F_17 ( T_3 V_13 , T_2 * V_4 )
{
return F_13 ( & V_13 , V_4 , 1 , V_32 , V_29 ) ;
}
int F_18 ( T_3 V_13 , T_3 * V_4 )
{
T_3 V_33 [ 2 ] = { V_13 , V_13 + 1 } ;
return F_13 ( V_33 , ( T_2 * ) V_4 , 2 , V_32 , V_29 ) ;
}
int F_19 ( T_3 V_13 , T_1 * V_4 )
{
T_3 V_33 [ 4 ] = { V_13 , V_13 + 1 , V_13 + 2 , V_13 + 3 } ;
return F_13 ( V_33 , ( T_2 * ) V_4 , 4 , V_32 , V_29 ) ;
}
int F_20 ( T_3 V_13 , T_2 V_4 )
{
return F_13 ( & V_13 , & V_4 , 1 , V_32 , V_31 ) ;
}
int F_21 ( T_3 V_13 , T_3 V_4 )
{
T_3 V_33 [ 2 ] = { V_13 , V_13 + 1 } ;
return F_13 ( V_33 , ( T_2 * ) & V_4 , 2 , V_32 , V_31 ) ;
}
int F_22 ( T_3 V_13 , T_1 V_4 )
{
T_3 V_33 [ 4 ] = { V_13 , V_13 + 1 , V_13 + 2 , V_13 + 3 } ;
return F_13 ( V_33 , ( T_2 * ) & V_4 , 4 , V_32 , V_31 ) ;
}
int F_23 ( T_3 * V_13 , T_2 * V_4 , int V_34 )
{
return F_13 ( V_13 , V_4 , V_34 , V_32 , V_29 ) ;
}
int F_24 ( T_3 * V_13 , T_2 * V_4 , int V_34 )
{
return F_13 ( V_13 , V_4 , V_34 , V_32 , V_31 ) ;
}
int F_25 ( T_3 V_13 , T_2 V_35 , T_2 V_36 )
{
T_2 V_4 [ 2 ] = { V_35 , V_36 } ;
return F_13 ( & V_13 , V_4 , 1 , V_32 , V_30 ) ;
}
int F_26 ( int V_1 , int V_37 )
{
int V_21 ;
F_14 ( & V_25 ) ;
if ( V_2 . V_9 == NULL ) {
F_15 ( & V_25 ) ;
return - V_26 ;
}
F_1 ( V_37 << 12 | V_1 ) ;
V_21 = F_10 () ;
F_15 ( & V_25 ) ;
return V_21 ;
}
int F_27 ( int V_1 , int V_37 , T_1 * V_38 , int V_39 ,
T_1 * V_40 , int V_41 )
{
int V_17 , V_21 ;
F_14 ( & V_25 ) ;
if ( V_2 . V_9 == NULL ) {
F_15 ( & V_25 ) ;
return - V_26 ;
}
for ( V_17 = 0 ; V_17 < V_39 ; V_17 ++ )
F_3 ( * V_38 ++ , 4 * V_17 ) ;
F_1 ( ( V_39 << 16 ) | ( V_37 << 12 ) | V_1 ) ;
V_21 = F_10 () ;
for ( V_17 = 0 ; V_17 < V_41 ; V_17 ++ )
* V_40 ++ = F_8 ( 4 * V_17 ) ;
F_15 ( & V_25 ) ;
return V_21 ;
}
int F_28 ( T_1 V_13 , T_1 * V_4 )
{
T_1 V_1 = 0 ;
F_14 ( & V_25 ) ;
if ( V_2 . V_9 == NULL ) {
F_15 ( & V_25 ) ;
return - V_26 ;
}
V_1 = ( V_13 >> 24 ) & 0xFF ;
if ( V_1 == V_42 ) {
F_2 ( V_13 , V_2 . V_43 + V_44 ) ;
F_29 ( 1 ) ;
* V_4 = F_9 ( V_2 . V_43 + V_45 ) ;
} else if ( V_1 == V_46 ) {
F_2 ( * V_4 , V_2 . V_43 + V_45 ) ;
F_29 ( 1 ) ;
F_2 ( V_13 , V_2 . V_43 + V_44 ) ;
} else {
F_12 ( & V_2 . V_9 -> V_10 ,
L_2 , V_1 ) ;
F_15 ( & V_25 ) ;
return - V_12 ;
}
F_15 ( & V_25 ) ;
return 0 ;
}
int F_30 ( T_2 * V_47 , T_1 V_48 )
{
void T_4 * V_49 ;
struct V_50 T_4 * V_51 = NULL ;
int V_52 = 0 ;
T_1 V_7 ;
F_14 ( & V_25 ) ;
V_49 = F_31 ( V_53 , ( 128 * 1024 ) ) ;
if ( V_49 == NULL ) {
F_15 ( & V_25 ) ;
return - V_54 ;
}
V_51 = F_31 ( V_55 ,
sizeof( struct V_50 ) ) ;
if ( V_51 == NULL ) {
F_32 ( V_49 ) ;
F_15 ( & V_25 ) ;
return - V_54 ;
}
F_1 ( V_56 ) ;
F_2 ( 0 , & V_51 -> V_7 ) ;
F_2 ( 0 , & V_51 -> V_57 ) ;
F_2 ( 0 , & V_51 -> V_58 ) ;
F_33 ( V_49 , V_47 , 0x800 ) ;
F_1 ( V_59 ) ;
while ( F_9 ( & V_51 -> V_57 ) != 1 ) {
F_34 () ;
F_29 ( 1 ) ;
}
while ( F_9 ( & V_51 -> V_7 ) != V_60 ) {
F_34 () ;
F_29 ( 10 ) ;
}
F_29 ( 10 ) ;
V_61:
if ( V_52 > 5 )
goto V_62;
if ( F_9 ( & V_51 -> V_7 ) != V_60 )
goto V_62;
V_47 = V_47 + 0x800 ;
F_33 ( V_49 , V_47 , 0x20000 ) ;
F_2 ( 1 , & V_51 -> V_58 ) ;
while ( F_9 ( & V_51 -> V_57 ) == 1 ) {
F_34 () ;
F_29 ( 1 ) ;
}
if ( F_9 ( & V_51 -> V_7 ) == V_63 )
goto V_62;
while ( F_9 ( & V_51 -> V_7 ) != V_64 ) {
F_34 () ;
F_29 ( 10 ) ;
}
F_29 ( 10 ) ;
if ( F_9 ( & V_51 -> V_7 ) != V_64 )
goto V_62;
V_47 = V_47 + 0x20000 ;
F_33 ( V_49 , V_47 , 0x20000 ) ;
F_2 ( 0 , & V_51 -> V_58 ) ;
while ( V_51 -> V_57 == 0 ) {
F_34 () ;
F_29 ( 1 ) ;
}
if ( F_9 ( & V_51 -> V_7 ) == V_63 )
goto V_62;
if ( F_9 ( & V_51 -> V_7 ) == V_60 ) {
++ V_52 ;
goto V_61;
}
V_62:
V_7 = F_9 ( & V_51 -> V_7 ) ;
F_32 ( V_49 ) ;
F_32 ( V_51 ) ;
F_15 ( & V_25 ) ;
if ( V_7 == V_65 )
return 0 ;
return - V_12 ;
}
static T_5 F_35 ( int V_66 , void * V_67 )
{
return V_68 ;
}
static int F_36 ( struct V_69 * V_10 , const struct V_70 * V_16 )
{
int V_21 ;
T_6 V_71 ;
if ( V_2 . V_9 )
return - V_72 ;
V_2 . V_9 = F_37 ( V_10 ) ;
V_21 = F_38 ( V_10 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_39 ( V_10 , L_3 ) ;
if ( V_21 )
return V_21 ;
V_71 = F_40 ( V_10 , 0 ) ;
if ( ! V_71 )
return - V_54 ;
if ( F_41 ( V_10 -> V_66 , F_35 , 0 , L_3 , & V_2 ) )
return - V_72 ;
V_2 . V_3 = F_31 ( V_73 , V_74 ) ;
if ( ! V_2 . V_3 )
return - V_54 ;
V_2 . V_43 = F_31 ( V_75 , V_76 ) ;
if ( ! V_2 . V_43 ) {
F_32 ( V_2 . V_3 ) ;
return - V_54 ;
}
F_42 () ;
return 0 ;
}
static void F_43 ( struct V_69 * V_9 )
{
F_44 ( V_9 -> V_66 , & V_2 ) ;
F_45 ( V_9 ) ;
F_46 ( V_2 . V_9 ) ;
F_32 ( V_2 . V_3 ) ;
F_32 ( V_2 . V_43 ) ;
V_2 . V_9 = NULL ;
F_47 () ;
}
static int T_7 F_48 ( void )
{
V_27 = F_49 () ;
if ( V_27 == 0 )
return - V_26 ;
return F_50 ( & V_77 ) ;
}
static void T_8 F_51 ( void )
{
F_52 ( & V_77 ) ;
}
