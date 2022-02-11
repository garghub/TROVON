static T_1 F_1 ( int V_1 , void * V_2 )
{
unsigned int V_3 = F_2 ( ( void V_4 * ) V_2 ) ;
F_3 ( F_4 ( V_3 ) ) ;
return V_5 ;
}
static int F_5 ( struct V_6 * V_7 , unsigned int V_8 )
{
return 0 ;
}
static int F_6 ( struct V_6 * V_7 )
{
unsigned int V_9 = F_7 ( V_7 -> V_1 ) - V_10 ;
if ( V_9 >= 0x3200 )
V_9 -= 0x3000 ;
else
V_9 -= 0x0200 ;
return F_8 ( ( V_9 >> 5 ) + 1 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
return V_7 -> V_1 + ( V_11 >> 5 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
F_11 ( V_12 , F_9 ( V_7 ) ) ;
F_11 ( V_12 , F_6 ( V_7 ) ) ;
}
static void F_12 ( struct V_6 * V_7 )
{
F_11 ( V_13 , F_6 ( V_7 ) ) ;
F_11 ( V_13 , F_9 ( V_7 ) ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
F_11 ( V_13 , F_6 ( V_7 ) ) ;
F_11 ( V_14 , F_9 ( V_7 ) ) ;
}
static void F_14 ( struct V_6 * V_7 )
{
F_11 ( V_15 , F_6 ( V_7 ) ) ;
}
static int F_15 ( struct V_6 * V_7 , unsigned int type )
{
return F_16 ( V_16 , F_9 ( V_7 ) , type ) ;
}
static int F_17 ( struct V_6 * V_7 ,
const struct V_17 * V_17 ,
bool V_18 )
{
return F_16 ( V_19 , F_6 ( V_7 ) , V_17 , V_18 ) ;
}
static int F_18 ( int V_1 )
{
unsigned int V_20 = V_1 - F_8 ( 1 ) ;
unsigned int V_21 ;
if ( V_20 < 16 )
V_21 = 0x0200 ;
else
V_21 = 0x3000 ;
return V_21 + ( V_20 << 5 ) ;
}
static T_1 F_19 ( int V_1 , void * V_2 )
{
F_3 ( F_4 ( F_18 ( V_1 ) ) ) ;
return V_5 ;
}
static void F_20 ( void V_4 * V_22 , void V_4 * V_23 , int V_24 )
{
unsigned long V_25 = F_2 ( V_22 ) & F_2 ( V_23 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 32 ; V_26 ++ ) {
if ( V_25 & ( 1 << ( 31 - V_26 ) ) ) {
F_3 ( V_24 + V_26 ) ;
F_21 ( ~ ( 1 << ( 31 - V_26 ) ) , V_22 ) ;
}
}
}
static T_1 F_22 ( int V_1 , void * V_2 )
{
F_20 ( V_27 , V_28 , F_23 ( 0 ) ) ;
return V_5 ;
}
static T_1 F_24 ( int V_1 , void * V_2 )
{
F_20 ( V_29 , V_30 , F_25 ( 0 ) ) ;
return V_5 ;
}
void T_2 F_26 ( void )
{
void V_4 * V_31 = F_27 ( 0xf0001000 ) ;
void V_4 * V_32 = F_27 ( 0xf0000100 ) ;
void V_4 * V_33 = F_28 ( 0xffd20100 , V_34 ) ;
int V_26 , V_35 ;
F_29 ( 0 , 29 , V_31 , V_32 ) ;
V_36 . V_37 = F_5 ;
F_30 ( & V_38 ) ;
F_30 ( & V_39 ) ;
F_30 ( & V_40 ) ;
F_30 ( & V_41 ) ;
V_42 . V_43 = L_1 ;
V_42 . V_44 = F_1 ;
V_42 . V_2 = V_33 ;
F_31 ( F_8 ( 50 ) , & V_42 ) ;
for ( V_26 = 0 ; V_26 < 32 ; V_26 ++ ) {
V_45 [ V_26 ] . V_43 = L_2 ;
V_45 [ V_26 ] . V_44 = F_19 ;
F_31 ( F_8 ( 1 + V_26 ) , & V_45 [ V_26 ] ) ;
V_35 = F_4 ( F_18 ( F_8 ( 1 + V_26 ) ) ) ;
F_32 ( F_33 ( V_35 , F_34 () ) != V_35 ) ;
F_35 ( V_35 , & V_46 ,
V_47 , L_3 ) ;
F_36 ( V_35 , V_48 ) ;
}
V_49 . V_43 = L_4 ;
V_49 . V_44 = F_22 ;
F_31 ( F_8 ( 33 ) , & V_49 ) ;
V_50 . V_43 = L_5 ;
V_50 . V_44 = F_24 ;
F_31 ( F_8 ( 34 ) , & V_50 ) ;
}
void T_2 F_37 ( void )
{
F_38 () ;
V_36 . V_37 = F_5 ;
}
