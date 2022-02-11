static void F_1 ( char V_1 )
{
T_1 T_2 * V_2 = ( T_1 T_2 V_3 * ) F_2 ( & V_4 [ 1 ] ) ;
if ( V_1 == '\n' )
F_1 ( '\r' ) ;
while ( F_2 ( & V_4 [ 0 ] ) & 0x80000000 )
;
F_3 ( V_2 , V_1 ) ;
F_4 ( & V_4 [ 0 ] , 0xa0000001 ) ;
}
void T_3 F_5 ( void )
{
if ( V_4 ) {
#ifdef F_6
F_7 ( 1 , 0xf0000000 , 0xf0000000 , 1024 * 1024 , V_5 ) ;
#endif
V_6 = F_1 ;
}
}
int F_8 ( void )
{
struct V_7 * V_8 ;
struct V_9 V_10 ;
T_4 V_11 [ V_12 ] = {} ;
T_5 V_13 = 0 ;
int V_14 = 0 ;
int V_15 = 0 ;
if ( V_16 )
return 0 ;
F_9 ( & V_17 ) ;
F_10 ( & V_18 , 1 ,
sizeof( V_19 ) /
sizeof( V_19 [ 0 ] ) ,
V_19 ) ;
V_8 = F_11 ( NULL , NULL , L_1 ) ;
if ( ! V_8 ) {
V_8 = F_12 ( NULL , L_2 ) ;
if ( ! V_8 ) {
F_13 ( V_20 L_3 ) ;
V_15 = - V_21 ;
goto V_22;
}
}
V_16 = F_14 ( V_8 , V_11 ) ;
if ( V_16 == ( V_23 ) V_24 ) {
F_13 ( V_20 L_4 ) ;
V_15 = - V_21 ;
goto V_22;
}
while ( F_15 ( V_8 , V_14 ++ , & V_10 ) == 0 ) {
if ( V_10 . V_25 > V_13 )
V_13 = V_10 . V_25 ;
F_16 ( & V_18 , V_10 . V_26 - V_16 ,
F_17 ( & V_10 ) ) ;
}
V_27 = F_18 ( V_16 , V_13 - V_16 + 1 ) ;
if ( ! V_27 ) {
F_13 ( V_20 L_5 ) ;
V_15 = - V_28 ;
}
V_22:
F_19 ( V_8 ) ;
return V_15 ;
}
unsigned long F_20 ( unsigned long V_29 , unsigned long V_30 )
{
unsigned long V_26 ;
unsigned long V_31 ;
F_21 ( & V_17 , V_31 ) ;
V_18 . V_32 = V_30 ;
V_26 = F_22 ( & V_18 , V_29 , L_6 ) ;
F_23 ( & V_17 , V_31 ) ;
return V_26 ;
}
int F_24 ( unsigned long V_33 )
{
int V_15 ;
unsigned long V_31 ;
F_21 ( & V_17 , V_31 ) ;
V_15 = F_25 ( & V_18 , V_33 ) ;
F_23 ( & V_17 , V_31 ) ;
return V_15 ;
}
unsigned long F_26 ( unsigned long V_33 , unsigned long V_29 )
{
unsigned long V_26 ;
unsigned long V_31 ;
F_21 ( & V_17 , V_31 ) ;
V_18 . V_32 = 1 ;
V_26 = F_27 ( & V_18 , V_33 , V_29 , L_6 ) ;
F_23 ( & V_17 , V_31 ) ;
return V_26 ;
}
void T_2 * F_28 ( unsigned long V_33 )
{
return V_27 + V_33 ;
}
unsigned long F_29 ( void T_2 * V_34 )
{
return V_34 - ( void T_2 * ) V_27 ;
}
T_6 F_30 ( void T_2 * V_34 )
{
return V_16 + ( ( T_1 T_2 * ) V_34 - V_27 ) ;
}
static inline struct V_35 *
F_31 ( struct V_36 * V_37 )
{
return F_32 ( V_37 , struct V_35 , V_37 ) ;
}
static void F_33 ( struct V_36 * V_37 )
{
struct V_35 * V_38 = F_31 ( V_37 ) ;
struct V_39 T_2 * V_40 = V_37 -> V_41 ;
V_38 -> V_42 = F_2 ( & V_40 -> V_43 ) ;
}
static int F_34 ( struct V_44 * V_45 , unsigned int V_46 )
{
struct V_36 * V_37 = F_35 ( V_45 ) ;
struct V_39 T_2 * V_40 = V_37 -> V_41 ;
T_4 V_47 ;
V_47 = 1 << ( 31 - V_46 ) ;
return ! ! ( F_2 ( & V_40 -> V_43 ) & V_47 ) ;
}
static void F_36 ( struct V_36 * V_37 , T_4 V_47 ,
int V_48 )
{
struct V_35 * V_38 = F_31 ( V_37 ) ;
struct V_39 T_2 * V_40 = V_37 -> V_41 ;
if ( V_48 )
V_38 -> V_42 |= V_47 ;
else
V_38 -> V_42 &= ~ V_47 ;
F_4 ( & V_40 -> V_43 , V_38 -> V_42 ) ;
}
static void F_37 ( struct V_44 * V_45 , unsigned int V_46 , int V_48 )
{
struct V_36 * V_37 = F_35 ( V_45 ) ;
struct V_35 * V_38 = F_31 ( V_37 ) ;
unsigned long V_31 ;
T_4 V_47 = 1 << ( 31 - V_46 ) ;
F_21 ( & V_38 -> V_49 , V_31 ) ;
F_36 ( V_37 , V_47 , V_48 ) ;
F_23 ( & V_38 -> V_49 , V_31 ) ;
}
static int F_38 ( struct V_44 * V_45 , unsigned int V_46 , int V_50 )
{
struct V_36 * V_37 = F_35 ( V_45 ) ;
struct V_35 * V_38 = F_31 ( V_37 ) ;
struct V_39 T_2 * V_40 = V_37 -> V_41 ;
unsigned long V_31 ;
T_4 V_47 = 1 << ( 31 - V_46 ) ;
F_21 ( & V_38 -> V_49 , V_31 ) ;
F_39 ( & V_40 -> V_51 , V_47 ) ;
F_36 ( V_37 , V_47 , V_50 ) ;
F_23 ( & V_38 -> V_49 , V_31 ) ;
return 0 ;
}
static int F_40 ( struct V_44 * V_45 , unsigned int V_46 )
{
struct V_36 * V_37 = F_35 ( V_45 ) ;
struct V_35 * V_38 = F_31 ( V_37 ) ;
struct V_39 T_2 * V_40 = V_37 -> V_41 ;
unsigned long V_31 ;
T_4 V_47 = 1 << ( 31 - V_46 ) ;
F_21 ( & V_38 -> V_49 , V_31 ) ;
F_41 ( & V_40 -> V_51 , V_47 ) ;
F_23 ( & V_38 -> V_49 , V_31 ) ;
return 0 ;
}
int F_42 ( struct V_7 * V_8 )
{
struct V_35 * V_38 ;
struct V_36 * V_37 ;
struct V_44 * V_45 ;
V_38 = F_43 ( sizeof( * V_38 ) , V_52 ) ;
if ( ! V_38 )
return - V_28 ;
F_9 ( & V_38 -> V_49 ) ;
V_37 = & V_38 -> V_37 ;
V_45 = & V_37 -> V_45 ;
V_37 -> V_53 = F_33 ;
V_45 -> V_54 = 32 ;
V_45 -> V_55 = F_40 ;
V_45 -> V_56 = F_38 ;
V_45 -> V_57 = F_34 ;
V_45 -> V_58 = F_37 ;
return F_44 ( V_8 , V_37 ) ;
}
