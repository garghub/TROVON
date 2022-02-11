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
static int F_17 ( struct V_6 * V_7 , unsigned int V_8 )
{
return F_16 ( V_17 , F_9 ( V_7 ) , V_8 ) ;
}
static int F_18 ( struct V_6 * V_7 ,
const struct V_18 * V_18 ,
bool V_19 )
{
return F_16 ( V_20 , F_6 ( V_7 ) , V_18 , V_19 ) ;
}
static int F_19 ( int V_1 )
{
unsigned int V_21 = V_1 - F_8 ( 1 ) ;
unsigned int V_22 ;
if ( V_21 < 16 )
V_22 = 0x0200 ;
else
V_22 = 0x3000 ;
return V_22 + ( V_21 << 5 ) ;
}
static T_1 F_20 ( int V_1 , void * V_2 )
{
F_3 ( F_4 ( F_19 ( V_1 ) ) ) ;
return V_5 ;
}
static void F_21 ( unsigned long V_23 , unsigned long V_24 , int V_25 )
{
unsigned long V_26 = F_2 ( V_23 ) & F_2 ( V_24 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < 32 ; V_27 ++ ) {
if ( V_26 & ( 1 << ( 31 - V_27 ) ) ) {
F_3 ( V_25 + V_27 ) ;
F_22 ( ~ ( 1 << ( 31 - V_27 ) ) , V_23 ) ;
}
}
}
static T_1 F_23 ( int V_1 , void * V_2 )
{
F_21 ( V_28 , V_29 , F_24 ( 0 ) ) ;
return V_5 ;
}
static T_1 F_25 ( int V_1 , void * V_2 )
{
F_21 ( V_30 , V_31 , F_26 ( 0 ) ) ;
return V_5 ;
}
void T_2 F_27 ( void )
{
void V_4 * V_32 = F_28 ( 0xf0001000 ) ;
void V_4 * V_33 = F_28 ( 0xf0000100 ) ;
void V_4 * V_34 = F_29 ( 0xffd20100 , V_35 ) ;
int V_27 , V_36 ;
F_30 ( 0 , 29 , V_32 , V_33 ) ;
V_37 . V_17 = F_5 ;
F_31 ( & V_38 ) ;
F_31 ( & V_39 ) ;
F_31 ( & V_40 ) ;
F_31 ( & V_41 ) ;
V_42 . V_43 = L_1 ;
V_42 . V_44 = F_1 ;
V_42 . V_2 = V_34 ;
F_32 ( F_8 ( 50 ) , & V_42 ) ;
for ( V_27 = 0 ; V_27 < 32 ; V_27 ++ ) {
V_45 [ V_27 ] . V_43 = L_2 ;
V_45 [ V_27 ] . V_44 = F_20 ;
F_32 ( F_8 ( 1 + V_27 ) , & V_45 [ V_27 ] ) ;
V_36 = F_4 ( F_19 ( F_8 ( 1 + V_27 ) ) ) ;
F_33 ( V_36 , & V_46 ,
V_47 , L_3 ) ;
F_34 ( V_36 , V_48 ) ;
}
V_49 . V_43 = L_4 ;
V_49 . V_44 = F_23 ;
F_32 ( F_8 ( 33 ) , & V_49 ) ;
V_50 . V_43 = L_5 ;
V_50 . V_44 = F_25 ;
F_32 ( F_8 ( 34 ) , & V_50 ) ;
}
