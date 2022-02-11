void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
int F_5 ( void )
{
int V_4 ;
if ( strncmp ( V_5 -> V_6 , L_1 , 6 ) == 0 )
V_4 = 0 ;
else
V_4 = - V_7 ;
return V_4 ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
struct V_10 * V_11 = & V_9 -> V_12 [ 0 ] ;
int V_13 ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 = V_16 | V_17 ;
V_11 -> V_18 = 0 ;
V_11 -> V_19 = V_20 | V_21 | V_22 ;
V_11 ++ ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 = 0xef600000 | V_23 | V_17 ;
V_11 -> V_18 = 0xef600000 ;
V_11 -> V_19 = V_20 | V_21 | V_22
| V_24 | V_25 ;
V_2 -> V_26 . V_27 = F_8 ( V_28 ) ;
for ( V_13 = 0 ; V_13 < F_9 ( V_9 -> V_29 ) ; V_13 ++ )
V_9 -> V_29 [ V_13 ] . V_30 = - 1 ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
int V_33 ;
T_1 V_34 ;
T_2 V_35 ;
T_2 V_36 ;
V_34 = V_32 -> V_37 ;
V_35 = ( V_32 -> V_37 >> 32 ) & 0xff ;
V_36 = ( V_32 -> V_37 >> 40 ) & 0x1 ;
V_33 = F_11 ( V_2 , V_34 , V_35 , V_36 ) ;
if ( V_33 == - 1 ) {
V_32 -> V_38 = 0 ;
return 0 ;
}
V_32 -> V_39 = F_12 ( V_2 , V_33 , V_34 ) ;
V_32 -> V_38 = 1 ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
F_14 ( V_2 , V_41 ) ;
}
int F_15 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
return F_16 ( V_2 , V_41 ) ;
}
struct V_1 * F_17 ( struct V_42 * V_42 , unsigned int V_43 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
int V_44 ;
V_9 = F_18 ( V_45 , V_46 ) ;
if ( ! V_9 ) {
V_44 = - V_47 ;
goto V_48;
}
V_2 = & V_9 -> V_2 ;
V_44 = F_19 ( V_2 , V_42 , V_43 ) ;
if ( V_44 )
goto V_49;
V_2 -> V_26 . V_50 = ( void * ) F_20 ( V_46 | V_51 ) ;
if ( ! V_2 -> V_26 . V_50 )
goto V_52;
return V_2 ;
V_52:
F_21 ( V_2 ) ;
V_49:
F_22 ( V_45 , V_9 ) ;
V_48:
return F_23 ( V_44 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
F_25 ( ( unsigned long ) V_2 -> V_26 . V_50 ) ;
F_21 ( V_2 ) ;
F_22 ( V_45 , V_9 ) ;
}
static int T_3 F_26 ( void )
{
int V_4 ;
V_4 = F_27 () ;
if ( V_4 )
return V_4 ;
return F_28 ( NULL , sizeof( struct V_8 ) , 0 , V_53 ) ;
}
static void T_4 F_29 ( void )
{
F_30 () ;
}
