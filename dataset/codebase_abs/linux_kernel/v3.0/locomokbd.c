static inline void F_1 ( unsigned long V_1 )
{
F_2 ( 0x00FF , V_1 + V_2 ) ;
}
static inline void F_3 ( unsigned long V_1 )
{
unsigned long V_3 ;
F_2 ( 0 , V_1 + V_2 ) ;
V_3 = F_4 ( V_1 + V_4 ) ;
V_3 &= 0xFEFF ;
F_2 ( V_3 , V_1 + V_4 ) ;
}
static inline void F_5 ( unsigned long V_1 , int V_5 )
{
unsigned short V_6 ;
unsigned short V_7 ;
V_6 = 0xFF & ~ ( 1 << V_5 ) ;
V_7 = ( V_6 << 8 ) + V_6 ;
F_2 ( V_7 , V_1 + V_2 ) ;
}
static inline void F_6 ( unsigned long V_1 , int V_5 )
{
unsigned short V_7 ;
V_7 = ( ( 0xFF & ~ ( 1 << V_5 ) ) << 8 ) + 0xFF ;
F_2 ( V_7 , V_1 + V_2 ) ;
}
static void F_7 ( struct V_8 * V_8 )
{
unsigned int V_9 , V_5 , V_10 ;
unsigned long V_11 ;
unsigned int V_12 ;
unsigned long V_1 = V_8 -> V_13 ;
F_8 ( & V_8 -> V_14 , V_11 ) ;
F_1 ( V_1 ) ;
V_12 = 0 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
F_5 ( V_1 , V_5 ) ;
F_9 ( V_16 ) ;
V_10 = ~ F_4 ( V_1 + V_17 ) ;
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ ) {
unsigned int V_19 , V_20 , V_21 ;
V_19 = F_10 ( V_5 , V_9 ) ;
V_20 = V_10 & F_11 ( V_9 ) ;
V_21 = V_8 -> V_22 [ V_19 ] ;
F_12 ( V_8 -> V_23 , V_21 , V_20 ) ;
if ( F_13 ( ! V_20 ) )
continue;
V_12 ++ ;
if ( F_14 ( V_21 == V_24 ) ) {
if ( ! F_15 ( V_25 ,
V_8 -> V_26 + V_27 ) )
continue;
if ( V_8 -> V_28 ++
!= ( V_27 / V_29 + 1 ) )
continue;
F_16 ( V_8 -> V_23 , V_30 ,
V_31 , 1 ) ;
V_8 -> V_26 = V_25 ;
} else
V_8 -> V_28 = 0 ;
}
F_6 ( V_1 , V_5 ) ;
}
F_3 ( V_1 ) ;
F_17 ( V_8 -> V_23 ) ;
if ( V_12 )
F_18 ( & V_8 -> V_32 , V_25 + V_29 ) ;
else
V_8 -> V_28 = 0 ;
F_19 ( & V_8 -> V_14 , V_11 ) ;
}
static T_1 F_20 ( int V_33 , void * V_34 )
{
struct V_8 * V_8 = V_34 ;
T_2 V_3 ;
V_3 = F_4 ( V_8 -> V_13 + V_4 ) ;
if ( ( V_3 & 0x0001 ) == 0 )
return V_35 ;
F_2 ( V_3 & ~ 0x0100 , V_8 -> V_13 + V_4 ) ;
F_9 ( 100 ) ;
F_7 ( V_8 ) ;
return V_35 ;
}
static void F_21 ( unsigned long V_36 )
{
struct V_8 * V_8 = (struct V_8 * ) V_36 ;
F_7 ( V_8 ) ;
}
static int F_22 ( struct V_37 * V_38 )
{
struct V_8 * V_8 = F_23 ( V_38 ) ;
T_2 V_3 ;
V_3 = F_4 ( V_8 -> V_13 + V_4 ) | 0x0010 ;
F_2 ( V_3 , V_8 -> V_13 + V_4 ) ;
return 0 ;
}
static void F_24 ( struct V_37 * V_38 )
{
struct V_8 * V_8 = F_23 ( V_38 ) ;
T_2 V_3 ;
V_3 = F_4 ( V_8 -> V_13 + V_4 ) & ~ 0x0010 ;
F_2 ( V_3 , V_8 -> V_13 + V_4 ) ;
}
static int T_3 F_25 ( struct V_39 * V_38 )
{
struct V_8 * V_8 ;
struct V_37 * V_37 ;
int V_40 , V_41 ;
V_8 = F_26 ( sizeof( struct V_8 ) , V_42 ) ;
V_37 = F_27 () ;
if ( ! V_8 || ! V_37 ) {
V_41 = - V_43 ;
goto V_44;
}
if ( ! F_28 ( ( unsigned long ) V_38 -> V_45 ,
V_38 -> V_46 ,
F_29 ( V_38 ) ) ) {
V_41 = - V_47 ;
F_30 ( V_48 L_1 ) ;
goto V_44;
}
F_31 ( V_38 , V_8 ) ;
V_8 -> V_13 = ( unsigned long ) V_38 -> V_45 ;
F_32 ( & V_8 -> V_14 ) ;
F_33 ( & V_8 -> V_32 ) ;
V_8 -> V_32 . V_49 = F_21 ;
V_8 -> V_32 . V_36 = ( unsigned long ) V_8 ;
V_8 -> V_26 = V_25 ;
V_8 -> V_23 = V_37 ;
strcpy ( V_8 -> V_50 , L_2 ) ;
V_37 -> V_51 = L_3 ;
V_37 -> V_50 = V_8 -> V_50 ;
V_37 -> V_52 . V_53 = V_54 ;
V_37 -> V_52 . V_55 = 0x0001 ;
V_37 -> V_52 . V_56 = 0x0001 ;
V_37 -> V_52 . V_57 = 0x0100 ;
V_37 -> V_58 = F_22 ;
V_37 -> V_59 = F_24 ;
V_37 -> V_38 . V_60 = & V_38 -> V_38 ;
V_37 -> V_61 [ 0 ] = F_34 ( V_62 ) | F_34 ( V_63 ) |
F_34 ( V_30 ) ;
V_37 -> V_22 = V_8 -> V_22 ;
V_37 -> V_64 = sizeof( V_65 [ 0 ] ) ;
V_37 -> V_66 = F_35 ( V_65 ) ;
F_36 ( V_37 , V_8 ) ;
memcpy ( V_8 -> V_22 , V_65 , sizeof( V_8 -> V_22 ) ) ;
for ( V_40 = 0 ; V_40 < V_67 ; V_40 ++ )
F_37 ( V_8 -> V_22 [ V_40 ] , V_37 -> V_68 ) ;
F_38 ( 0 , V_37 -> V_68 ) ;
V_41 = F_39 ( V_38 -> V_33 [ 0 ] , F_20 , 0 , L_4 , V_8 ) ;
if ( V_41 ) {
F_30 ( V_48 L_5 ) ;
goto V_69;
}
V_41 = F_40 ( V_8 -> V_23 ) ;
if ( V_41 )
goto V_70;
return 0 ;
V_70:
F_41 ( V_38 -> V_33 [ 0 ] , V_8 ) ;
V_69:
F_42 ( ( unsigned long ) V_38 -> V_45 , V_38 -> V_46 ) ;
F_31 ( V_38 , NULL ) ;
V_44:
F_43 ( V_37 ) ;
F_44 ( V_8 ) ;
return V_41 ;
}
static int T_4 F_45 ( struct V_39 * V_38 )
{
struct V_8 * V_8 = F_46 ( V_38 ) ;
F_41 ( V_38 -> V_33 [ 0 ] , V_8 ) ;
F_47 ( & V_8 -> V_32 ) ;
F_48 ( V_8 -> V_23 ) ;
F_31 ( V_38 , NULL ) ;
F_42 ( ( unsigned long ) V_38 -> V_45 , V_38 -> V_46 ) ;
F_44 ( V_8 ) ;
return 0 ;
}
static int T_5 F_49 ( void )
{
return F_50 ( & V_71 ) ;
}
static void T_6 F_51 ( void )
{
F_52 ( & V_71 ) ;
}
