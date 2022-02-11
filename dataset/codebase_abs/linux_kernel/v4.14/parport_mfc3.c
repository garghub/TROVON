static inline int F_1 ( void * V_1 , ... ) { return 0 ; }
static void F_2 ( struct V_2 * V_3 , unsigned char V_4 )
{
F_1 ( V_5 L_1 , V_4 ) ;
V_6 = F_3 ( V_3 ) -> V_7 ;
F_3 ( V_3 ) -> V_7 = V_4 ;
}
static unsigned char F_4 ( struct V_2 * V_3 )
{
return F_3 ( V_3 ) -> V_7 ;
}
static unsigned char F_5 ( unsigned char V_8 )
{
unsigned char V_9 = 32 | 64 ;
if ( V_8 & V_10 )
V_9 &= ~ 32 ;
if ( V_8 & V_11 )
V_9 |= 128 ;
if ( V_8 & V_12 )
V_9 &= ~ 64 ;
if ( V_8 & V_13 )
;
return V_9 ;
}
static unsigned char F_6 ( unsigned char V_8 )
{
unsigned char V_9 = V_13
| V_12 | V_10 ;
if ( V_8 & 128 )
V_9 |= V_11 ;
if ( V_8 & 64 )
V_9 &= ~ V_12 ;
if ( V_8 & 32 )
V_9 &= ~ V_10 ;
return V_9 ;
}
static void F_7 ( struct V_2 * V_3 , unsigned char V_8 )
{
F_1 ( V_5 L_2 , V_8 ) ;
F_3 ( V_3 ) -> V_14 = ( F_3 ( V_3 ) -> V_14 & 0x1f ) | F_5 ( V_8 ) ;
}
static unsigned char F_8 ( struct V_2 * V_3 )
{
F_1 ( V_5 L_3 ) ;
return F_6 ( F_3 ( V_3 ) -> V_14 & 0xe0 ) ;
}
static unsigned char F_9 ( struct V_2 * V_3 , unsigned char V_15 , unsigned char V_16 )
{
unsigned char V_17 ;
F_1 ( V_5 L_4 , V_15 , V_16 ) ;
V_17 = F_8 ( V_3 ) ;
F_7 ( V_3 , ( V_17 & ~ V_15 ) ^ V_16 ) ;
return V_17 ;
}
static unsigned char F_10 ( unsigned char V_18 )
{
unsigned char V_9 = V_19 ;
if ( V_18 & 1 )
V_9 &= ~ V_19 ;
if ( V_18 & 2 )
V_9 |= V_20 ;
if ( V_18 & 4 )
V_9 |= V_21 ;
if ( V_18 & 8 )
V_9 |= V_22 ;
if ( V_18 & 16 )
V_9 |= V_23 ;
return V_9 ;
}
static unsigned char F_11 ( struct V_2 * V_3 )
{
unsigned char V_18 ;
V_18 = F_10 ( F_3 ( V_3 ) -> V_14 & 0x1f ) ;
F_1 ( V_5 L_5 , V_18 ) ;
return V_18 ;
}
static T_1 F_12 ( int V_24 , void * V_25 )
{
int V_26 ;
for( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
if ( V_28 [ V_26 ] != NULL )
if ( F_3 ( V_28 [ V_26 ] ) -> V_29 & 128 ) {
V_6 = F_3 ( V_28 [ V_26 ] ) -> V_7 ;
F_13 ( V_28 [ V_26 ] ) ;
}
return V_30 ;
}
static void F_14 ( struct V_2 * V_3 )
{
F_3 ( V_3 ) -> V_29 |= V_31 ;
}
static void F_15 ( struct V_2 * V_3 )
{
F_3 ( V_3 ) -> V_29 &= ~ V_31 ;
}
static void F_16 ( struct V_2 * V_3 )
{
F_1 ( V_5 L_6 ) ;
F_3 ( V_3 ) -> V_29 &= ~ V_32 ;
F_3 ( V_3 ) -> V_33 = 255 ;
F_3 ( V_3 ) -> V_29 |= V_32 ;
}
static void F_17 ( struct V_2 * V_3 )
{
F_1 ( V_5 L_7 ) ;
F_3 ( V_3 ) -> V_29 &= ~ V_32 ;
F_3 ( V_3 ) -> V_33 = 0 ;
F_3 ( V_3 ) -> V_29 |= V_32 ;
}
static void F_18 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
V_37 -> V_38 . V_39 . V_4 = 0 ;
V_37 -> V_38 . V_39 . V_40 = 255 ;
V_37 -> V_38 . V_39 . V_18 = 0 ;
V_37 -> V_38 . V_39 . V_41 = 0xe0 ;
}
static void F_19 ( struct V_2 * V_3 , struct V_36 * V_37 )
{
V_37 -> V_38 . V_39 . V_4 = F_3 ( V_3 ) -> V_7 ;
F_3 ( V_3 ) -> V_29 &= ~ V_32 ;
V_37 -> V_38 . V_39 . V_40 = F_3 ( V_3 ) -> V_33 ;
F_3 ( V_3 ) -> V_29 |= V_32 ;
V_37 -> V_38 . V_39 . V_18 = F_3 ( V_3 ) -> V_14 ;
F_3 ( V_3 ) -> V_42 &= ~ V_32 ;
V_37 -> V_38 . V_39 . V_41 = F_3 ( V_3 ) -> V_33 ;
F_3 ( V_3 ) -> V_42 |= V_32 ;
}
static void F_20 ( struct V_2 * V_3 , struct V_36 * V_37 )
{
F_3 ( V_3 ) -> V_7 = V_37 -> V_38 . V_39 . V_4 ;
F_3 ( V_3 ) -> V_29 &= ~ V_32 ;
F_3 ( V_3 ) -> V_33 = V_37 -> V_38 . V_39 . V_40 ;
F_3 ( V_3 ) -> V_29 |= V_32 ;
F_3 ( V_3 ) -> V_14 = V_37 -> V_38 . V_39 . V_18 ;
F_3 ( V_3 ) -> V_42 &= ~ V_32 ;
F_3 ( V_3 ) -> V_33 = V_37 -> V_38 . V_39 . V_41 ;
F_3 ( V_3 ) -> V_42 |= V_32 ;
}
static int T_2 F_21 ( void )
{
struct V_2 * V_3 ;
int V_43 = 0 ;
struct F_3 * V_44 ;
struct V_45 * V_46 = NULL ;
if ( ! V_47 )
return - V_48 ;
while ( ( V_46 = F_22 ( V_49 , V_46 ) ) ) {
unsigned long V_50 = V_46 -> V_51 . V_52 + V_53 ;
if ( ! F_23 ( V_50 , sizeof( struct F_3 ) , L_8 ) )
continue;
V_44 = F_24 ( V_50 ) ;
V_44 -> V_29 = 0 ;
V_44 -> V_33 = 255 ;
V_44 -> V_29 = V_32 | 32 | 8 ;
V_6 = V_44 -> V_33 ;
V_44 -> V_42 = 0 ;
V_44 -> V_54 = 0xe0 ;
V_44 -> V_42 = V_32 ;
V_44 -> V_14 = 0 ;
F_25 ( 10 ) ;
V_44 -> V_14 = 128 ;
V_3 = F_26 ( ( unsigned long ) V_44 , V_55 ,
V_56 , & V_57 ) ;
if ( ! V_3 )
goto V_58;
if ( V_3 -> V_24 != V_59 ) {
if ( V_60 ++ == 0 )
if ( F_27 ( V_55 , F_12 , V_61 , V_3 -> V_62 , & V_57 ) )
goto V_63;
}
V_3 -> V_35 = & V_46 -> V_35 ;
V_28 [ V_43 ++ ] = V_3 ;
F_28 ( V_64 L_9 , V_3 -> V_62 ) ;
V_3 -> V_65 = ( void * ) V_50 ;
F_29 ( V_3 ) ;
if ( V_43 >= V_27 )
break;
continue;
V_63:
F_30 ( V_3 ) ;
V_58:
F_31 ( V_50 , sizeof( struct F_3 ) ) ;
}
return V_43 ? 0 : - V_48 ;
}
static void T_3 F_32 ( void )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
if ( ! V_28 [ V_26 ] )
continue;
F_33 ( V_28 [ V_26 ] ) ;
if ( V_28 [ V_26 ] -> V_24 != V_59 ) {
if ( -- V_60 == 0 )
F_34 ( V_55 , & V_57 ) ;
}
F_31 ( F_35 ( V_28 [ V_26 ] -> V_65 ) , sizeof( struct F_3 ) ) ;
F_30 ( V_28 [ V_26 ] ) ;
}
}
