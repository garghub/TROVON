static unsigned short F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static unsigned short F_3 ( struct V_1 * V_2 , unsigned short V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned short V_5 , unsigned short V_3 )
{
F_6 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned short V_5 , unsigned short V_3 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int T_1 F_9 ( struct V_6 * V_7 , const struct V_8 * V_9 )
{
static int V_10 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_13 ;
unsigned int V_14 ;
unsigned long V_15 ;
struct V_16 * V_17 = & V_18 [ V_9 -> V_19 ] ;
if ( V_10 ++ == 0 )
F_10 ( L_1 , V_20 ) ;
if ( F_11 ( V_7 ) )
return - V_21 ;
V_14 = V_7 -> V_22 ;
V_15 = F_12 ( V_7 , 0 ) ;
V_2 = F_13 ( sizeof( struct V_11 ) ) ;
if ( ! V_2 )
return - V_23 ;
if ( ! F_14 ( V_15 , V_24 , V_2 -> V_25 ) ) {
V_13 = - V_26 ;
goto V_27;
}
V_2 -> V_4 = V_15 ;
V_2 -> V_22 = V_14 ;
V_2 -> V_28 = 0 ;
F_15 ( & V_7 -> V_2 , L_2 , V_17 -> V_25 ) ;
F_15 ( & V_7 -> V_2 , L_3 , V_2 -> V_4 , V_2 -> V_22 ) ;
F_16 ( V_2 ) ;
F_15 ( & V_7 -> V_2 , L_4 , V_2 -> V_29 ) ;
V_13 = F_17 ( V_2 , & V_7 -> V_2 ) ;
if ( V_13 ) {
F_15 ( & V_7 -> V_2 , L_5 ) ;
goto V_30;
}
V_12 = F_18 ( V_2 ) ;
V_12 -> V_31 = V_32 ;
V_12 -> V_33 = F_1 ;
V_12 -> V_34 = F_3 ;
V_12 -> V_35 = F_5 ;
V_12 -> V_36 = F_7 ;
memcpy ( V_12 -> V_37 , V_17 -> V_25 , V_38 + 1 ) ;
V_12 -> V_39 = V_17 ;
V_2 -> V_40 = & V_41 ;
V_13 = F_19 ( V_7 -> V_22 , V_42 , V_43 ,
V_2 -> V_25 , V_2 ) ;
if ( V_13 )
goto V_44;
F_20 ( V_7 , V_2 ) ;
F_21 ( V_2 , & V_7 -> V_2 ) ;
V_13 = F_22 ( V_2 ) ;
if ( V_13 )
goto V_45;
return 0 ;
V_45:
F_23 ( V_7 -> V_22 , V_2 ) ;
V_44:
F_20 ( V_7 , NULL ) ;
F_24 ( V_2 ) ;
V_30:
F_25 ( V_15 , V_24 ) ;
V_27:
F_26 ( V_2 ) ;
return V_13 ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_46 ;
F_7 ( V_2 , 0 , V_47 ) ;
F_7 ( V_2 , 0 , V_48 ) ;
V_2 -> V_49 = 6 ;
for( V_46 = 0 ; V_46 < 6 ; V_46 ++ )
V_2 -> V_29 [ V_46 ] = F_3 ( V_2 , V_50 ) >> 8 ;
}
static unsigned short V_32 ( struct V_1 * V_2 )
{
unsigned short V_5 = 0 ;
struct V_11 * V_12 = F_18 ( V_2 ) ;
struct V_16 * V_17 = V_12 -> V_39 ;
if( V_12 -> V_51 == V_52 )
V_5 |= V_17 -> V_53 [ 0 ] ;
else
V_5 |= V_17 -> V_53 [ 1 ] ;
return V_5 ;
}
static void T_2 F_27 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_28 ( V_7 ) ;
F_29 ( ! V_2 ) ;
F_30 ( V_2 ) ;
F_25 ( V_2 -> V_4 , V_24 ) ;
F_23 ( V_2 -> V_22 , V_2 ) ;
F_24 ( V_2 ) ;
F_26 ( V_2 ) ;
F_20 ( V_7 , NULL ) ;
}
static int T_3 F_31 ( void )
{
return F_32 ( & V_54 ) ;
}
static void T_4 F_33 ( void )
{
F_34 ( & V_54 ) ;
}
