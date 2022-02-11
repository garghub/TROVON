static void T_1 * F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_11 , V_12 ;
if ( V_6 -> V_13 != V_2 -> V_14 || F_2 ( V_3 ) )
return NULL ;
V_11 = F_3 ( V_3 ) ;
if ( V_11 > 2 )
return NULL ;
V_12 = V_11 ? V_15 | V_16 :
V_17 | V_16 ;
F_4 ( V_12 , V_9 -> V_18 + V_19 ) ;
return V_9 -> V_18 + ( V_11 >> 1 ) * 0x100 + V_4 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_20 , T_2 * V_12 )
{
void T_1 * V_18 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_18 )
return V_21 ;
switch ( V_20 ) {
case 1 :
* V_12 = F_6 ( V_18 ) ;
break;
case 2 :
* V_12 = F_7 ( V_18 ) ;
break;
default:
* V_12 = F_8 ( V_18 ) ;
break;
}
return V_22 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_20 , T_2 V_12 )
{
void T_1 * V_18 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( ! V_18 )
return V_21 ;
switch ( V_20 ) {
case 1 :
F_10 ( V_12 , V_18 ) ;
break;
case 2 :
F_11 ( V_12 , V_18 ) ;
break;
default:
F_4 ( V_12 , V_18 ) ;
break;
}
return V_22 ;
}
static int T_3 F_12 ( const struct V_23 * V_24 , T_4 V_11 , T_4 V_25 )
{
struct V_5 * V_6 = V_24 -> V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
return V_9 -> V_26 ;
}
static int T_3 F_13 ( int V_27 , struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
void T_1 * V_18 = V_9 -> V_18 ;
T_2 V_12 ;
F_14 ( V_9 -> V_24 ) ;
F_15 ( V_9 -> V_24 ) ;
V_12 = F_8 ( V_18 + V_28 ) ;
F_16 ( V_9 -> V_24 , L_1 , V_6 -> V_13 , V_12 ) ;
V_12 = F_8 ( V_18 + V_29 ) & ~ V_30 ;
V_12 |= V_31 | V_32 ;
F_4 ( V_12 , V_18 + V_29 ) ;
F_17 ( 4 ) ;
V_12 &= ~ ( V_33 | V_34 |
V_31 | V_32 ) ;
F_4 ( V_12 | V_35 , V_18 + V_29 ) ;
F_4 ( V_36 , V_18 + V_37 ) ;
V_12 = F_8 ( V_18 + V_38 ) ;
V_12 |= V_39 | V_40 |
V_41 ;
F_4 ( V_12 , V_18 + V_38 ) ;
F_4 ( 0x40000000 | V_42 ,
V_18 + V_43 ) ;
V_12 = V_9 -> V_44 . V_45 | V_46 ;
F_4 ( V_12 , V_18 + V_47 ) ;
F_4 ( V_17 | V_16 ,
V_18 + V_19 ) ;
F_4 ( 0x40000000 | V_48 ,
V_18 + V_49 ) ;
V_12 = V_9 -> V_50 -> V_45 + V_51 ;
F_4 ( V_12 , V_18 + V_52 ) ;
V_12 = F_8 ( V_18 + V_53 ) ;
V_12 |= V_54 | V_55 |
V_56 | V_57 ;
F_4 ( V_12 , V_18 + V_53 ) ;
F_4 ( V_58 | V_59 | V_60 ,
V_18 + V_61 ) ;
F_18 ( & V_6 -> V_62 , & V_9 -> V_63 ) ;
F_18 ( & V_6 -> V_62 , & V_9 -> V_44 ) ;
return 1 ;
}
static int T_3 F_19 ( struct V_8 * V_9 )
{
void * * V_10 ;
int V_64 ;
if ( V_65 . V_66 < V_67 )
goto V_68;
V_64 = V_67 + V_69 ;
V_10 = F_20 ( V_64 * sizeof( void * ) , V_70 ) ;
if ( ! V_10 )
return - V_71 ;
V_67 = V_64 ;
if ( V_65 . V_10 ) {
memcpy ( V_10 , V_65 . V_10 ,
V_65 . V_66 * sizeof( void * ) ) ;
F_21 ( V_65 . V_10 ) ;
}
V_65 . V_10 = V_10 ;
V_68:
V_65 . V_10 [ V_65 . V_66 ++ ] = V_9 ;
return 0 ;
}
static int T_3 F_22 ( struct V_72 * V_73 )
{
struct V_74 * V_50 , * V_44 ;
struct V_8 * V_9 ;
void T_1 * V_18 ;
V_50 = F_23 ( V_73 , V_75 , 0 ) ;
V_18 = F_24 ( & V_73 -> V_24 , V_50 ) ;
if ( F_25 ( V_18 ) )
return F_26 ( V_18 ) ;
V_44 = F_23 ( V_73 , V_75 , 1 ) ;
if ( ! V_44 || ! V_44 -> V_45 )
return - V_76 ;
V_9 = F_27 ( & V_73 -> V_24 ,
sizeof( struct V_8 ) , V_70 ) ;
if ( ! V_9 )
return - V_71 ;
V_9 -> V_44 = * V_44 ;
V_9 -> V_63 . V_45 = V_9 -> V_44 . V_45 ;
V_9 -> V_63 . V_77 = V_9 -> V_44 . V_77 ;
V_9 -> V_63 . V_78 = V_79 ;
V_9 -> V_50 = V_50 ;
V_9 -> V_26 = F_28 ( V_73 , 0 ) ;
V_9 -> V_18 = V_18 ;
V_9 -> V_24 = & V_73 -> V_24 ;
return F_19 ( V_9 ) ;
}
static int T_3 F_29 ( void )
{
int V_80 ;
V_80 = F_30 ( & V_81 , F_22 ) ;
if ( ! V_80 )
F_31 ( & V_65 ) ;
F_21 ( V_65 . V_10 ) ;
V_65 . V_10 = NULL ;
return V_80 ;
}
