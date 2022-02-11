static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
F_2 ( V_4 , & V_5 , 1 ) ;
F_2 ( V_4 , NULL , V_5 ) ;
return V_2 -> V_6 -> V_7 ( V_2 -> V_6 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 ;
T_1 V_5 ;
T_1 V_10 [ V_11 ] ;
struct V_12 * V_13 ;
struct V_14 * V_15 = F_4 ( V_2 , struct V_14 , V_16 ) ;
V_13 = F_5 ( V_4 ) ;
F_6 ( V_13 ) ;
V_13 -> V_17 = F_7 ( V_18 ) ;
V_9 = F_8 ( V_4 ) ;
V_5 = ( V_9 -> V_19 + V_20 ) & ( V_11 - 1 ) ;
if ( F_9 ( V_13 ) < V_21 + V_20 + V_5 ) {
F_10 ( L_1 ) ;
F_11 ( V_13 ) ;
return - V_22 ;
}
memset ( V_10 , 0 , V_5 ) ;
F_12 ( V_4 , V_10 , V_5 ) ;
F_12 ( V_4 , & V_5 , 1 ) ;
F_12 ( V_4 , V_15 -> V_23 , sizeof( V_15 -> V_23 ) ) ;
return V_2 -> V_24 -> V_25 ( V_2 -> V_24 , V_4 ) ;
}
static void F_13 ( struct V_1 * V_2 , enum V_26 V_27 ,
int V_28 )
{
if ( V_2 -> V_6 && V_2 -> V_6 -> V_29 )
V_2 -> V_6 -> V_29 ( V_2 -> V_6 , V_27 , V_2 -> V_30 ) ;
}
static struct V_1 * F_14 ( int V_28 , T_1 V_31 [ V_32 ] ,
T_1 V_33 [ V_32 ] )
{
struct V_14 * V_34 = F_15 ( sizeof( struct V_14 ) , V_35 ) ;
if ( ! V_34 ) {
F_10 ( L_2 ) ;
return NULL ;
}
F_16 ( F_17 ( struct V_14 , V_16 ) == 0 ) ;
memset ( V_34 , 0 , sizeof( struct V_1 ) ) ;
V_34 -> V_16 . V_7 = F_1 ;
V_34 -> V_16 . V_25 = F_3 ;
V_34 -> V_16 . V_29 = F_13 ;
snprintf ( V_34 -> V_16 . V_36 , V_37 , L_3 , V_28 ) ;
V_34 -> V_16 . V_30 = V_28 ;
memcpy ( & V_34 -> V_23 [ V_32 ] , V_33 , V_32 ) ;
memcpy ( & V_34 -> V_23 [ V_32 ] , V_31 , V_32 ) ;
V_34 -> V_23 [ 12 ] = F_18 ( V_38 ) & 0xff ;
V_34 -> V_23 [ 13 ] = ( F_18 ( V_38 ) >> 8 ) & 0xff ;
F_19 ( L_4 ,
V_34 -> V_23 , V_34 -> V_23 + V_32 ,
V_34 -> V_23 [ 12 ] , V_34 -> V_23 [ 13 ] ) ;
return (struct V_1 * ) V_34 ;
}
static int F_20 ( struct V_39 * V_40 , unsigned long V_41 ,
void * V_42 )
{
struct V_43 * V_44 = F_21 ( V_42 ) ;
struct V_45 V_46 ;
struct V_1 * V_16 , * V_47 ;
struct V_48 * V_48 ;
struct V_49 * V_50 ;
if ( ! ( V_44 -> V_44 . V_51 && V_44 -> V_44 . V_51 -> V_52 &&
strcmp ( V_44 -> V_44 . V_51 -> V_52 -> V_36 , L_5 ) == 0 ) )
return 0 ;
V_48 = F_22 ( V_44 ) ;
V_50 = V_48 -> V_53 ;
F_19 ( L_6 ,
F_23 ( V_50 -> V_54 . V_55 ) ,
F_23 ( V_50 -> V_54 . V_56 ) ) ;
if ( ! ( F_23 ( V_50 -> V_54 . V_55 ) == V_57 &&
F_23 ( V_50 -> V_54 . V_56 ) == V_58 ) )
return 0 ;
if ( V_41 == V_59 )
F_24 ( V_60 ) ;
if ( V_41 != V_61 )
return 0 ;
F_25 ( V_60 ) ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_62 = false ;
V_46 . V_63 = false ;
V_46 . V_64 = false ;
V_46 . V_65 = V_66 ;
V_46 . V_67 = NULL ;
V_47 = F_14 ( V_44 -> V_68 , V_44 -> V_69 ,
V_44 -> V_70 ) ;
if ( ! V_47 )
return - V_71 ;
if ( V_44 -> V_72 > 1 )
F_10 ( L_7 ) ;
F_26 ( V_44 , & V_46 , V_47 , V_73 ,
& V_16 , & V_74 . V_75 ) ;
if ( ! V_76 )
F_27 ( & V_74 ) ;
V_76 = true ;
strncpy ( V_16 -> V_36 , V_44 -> V_36 ,
sizeof( V_16 -> V_36 ) - 1 ) ;
V_16 -> V_36 [ sizeof( V_16 -> V_36 ) - 1 ] = 0 ;
return 0 ;
}
static int T_2 F_28 ( void )
{
return F_29 ( & V_77 ) ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_77 ) ;
F_32 ( & V_74 ) ;
}
