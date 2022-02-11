static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_1 * V_4 ;
const struct V_5 * V_6 ;
struct V_5 * V_7 ;
const struct V_8 * V_9 ;
struct V_8 V_10 , * V_11 ;
if ( F_2 ( V_2 ) -> V_12 & F_3 ( V_13 ) )
return;
V_9 = F_4 ( V_2 , F_5 ( V_2 ) ,
sizeof( V_10 ) , & V_10 ) ;
if ( V_9 == NULL )
return;
if ( V_9 -> V_14 )
return;
if ( F_6 ( V_2 ) -> V_15 & ( V_16 | V_17 ) )
return;
if ( F_7 ( V_2 , V_3 , F_5 ( V_2 ) , V_18 ) )
return;
V_6 = F_2 ( V_2 ) ;
V_4 = F_8 ( sizeof( struct V_5 ) + sizeof( struct V_8 ) +
V_19 , V_20 ) ;
if ( ! V_4 )
return;
F_9 ( V_4 , V_19 ) ;
F_10 ( V_4 ) ;
V_7 = (struct V_5 * ) F_11 ( V_4 , sizeof( struct V_5 ) ) ;
V_7 -> V_21 = 4 ;
V_7 -> V_22 = sizeof( struct V_5 ) / 4 ;
V_7 -> V_23 = 0 ;
V_7 -> V_24 = 0 ;
V_7 -> V_12 = F_3 ( V_25 ) ;
V_7 -> V_26 = V_18 ;
V_7 -> V_27 = 0 ;
V_7 -> V_28 = V_6 -> V_29 ;
V_7 -> V_29 = V_6 -> V_28 ;
F_12 ( V_4 ) ;
V_11 = (struct V_8 * ) F_11 ( V_4 , sizeof( struct V_8 ) ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_30 = V_9 -> V_31 ;
V_11 -> V_31 = V_9 -> V_30 ;
V_11 -> V_32 = sizeof( struct V_8 ) / 4 ;
if ( V_9 -> V_33 )
V_11 -> V_34 = V_9 -> V_35 ;
else {
V_11 -> V_35 = F_13 ( F_14 ( V_9 -> V_34 ) + V_9 -> V_36 + V_9 -> V_37 +
V_2 -> V_38 - F_5 ( V_2 ) -
( V_9 -> V_32 << 2 ) ) ;
V_11 -> V_33 = 1 ;
}
V_11 -> V_14 = 1 ;
V_11 -> V_27 = ~ F_15 ( sizeof( struct V_8 ) , V_7 -> V_28 ,
V_7 -> V_29 , 0 ) ;
V_4 -> V_39 = V_40 ;
V_4 -> V_41 = ( unsigned char * ) V_11 - V_4 -> V_42 ;
V_4 -> V_43 = F_16 ( struct V_8 , V_27 ) ;
F_17 ( V_4 , F_18 ( V_2 ) ) ;
V_4 -> V_26 = F_3 ( V_44 ) ;
if ( F_19 ( V_4 , V_45 ) )
goto V_46;
V_7 -> V_47 = F_20 ( F_18 ( V_4 ) ) ;
if ( V_4 -> V_38 > F_21 ( F_18 ( V_4 ) ) )
goto V_46;
F_22 ( V_4 , V_2 ) ;
F_23 ( V_4 ) ;
return;
V_46:
F_24 ( V_4 ) ;
}
static inline void F_25 ( struct V_1 * V_48 , int V_49 )
{
F_26 ( V_48 , V_50 , V_49 , 0 ) ;
}
static unsigned int
F_27 ( struct V_1 * V_51 , const struct V_52 * V_53 )
{
const struct V_54 * V_55 = V_53 -> V_56 ;
switch ( V_55 -> V_57 ) {
case V_58 :
F_25 ( V_51 , V_59 ) ;
break;
case V_60 :
F_25 ( V_51 , V_61 ) ;
break;
case V_62 :
F_25 ( V_51 , V_63 ) ;
break;
case V_64 :
F_25 ( V_51 , V_65 ) ;
break;
case V_66 :
F_25 ( V_51 , V_67 ) ;
break;
case V_68 :
F_25 ( V_51 , V_69 ) ;
break;
case V_70 :
F_25 ( V_51 , V_71 ) ;
break;
case V_72 :
F_1 ( V_51 , V_53 -> V_73 ) ;
case V_74 :
break;
}
return V_75 ;
}
static int F_28 ( const struct V_76 * V_53 )
{
const struct V_54 * V_77 = V_53 -> V_56 ;
const struct V_78 * V_79 = V_53 -> V_80 ;
if ( V_77 -> V_57 == V_74 ) {
F_29 ( L_1 ) ;
return - V_81 ;
} else if ( V_77 -> V_57 == V_72 ) {
if ( V_79 -> V_82 . V_83 != V_18 ||
( V_79 -> V_82 . V_84 & V_85 ) ) {
F_29 ( L_2 ) ;
return - V_81 ;
}
}
return 0 ;
}
static int T_1 F_30 ( void )
{
return F_31 ( & V_86 ) ;
}
static void T_2 F_32 ( void )
{
F_33 ( & V_86 ) ;
}
