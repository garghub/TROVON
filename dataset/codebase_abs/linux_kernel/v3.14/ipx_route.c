struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
F_2 ( & V_4 ) ;
F_3 (r, &ipx_routes, node)
if ( V_3 -> V_5 == V_2 ) {
F_4 ( V_3 ) ;
goto V_6;
}
V_3 = NULL ;
V_6:
F_5 ( & V_4 ) ;
return V_3 ;
}
int F_6 ( T_1 V_7 , struct V_8 * V_9 ,
unsigned char * V_10 )
{
struct V_1 * V_11 ;
int V_12 ;
V_11 = F_1 ( V_7 ) ;
if ( ! V_11 ) {
V_11 = F_7 ( sizeof( * V_11 ) , V_13 ) ;
V_12 = - V_14 ;
if ( ! V_11 )
goto V_15;
F_8 ( & V_11 -> V_16 , 1 ) ;
F_4 ( V_11 ) ;
F_9 ( & V_4 ) ;
F_10 ( & V_11 -> V_10 , & V_17 ) ;
F_11 ( & V_4 ) ;
} else {
V_12 = - V_18 ;
if ( V_9 == V_19 )
goto V_20;
}
V_11 -> V_5 = V_7 ;
V_11 -> V_21 = V_9 ;
if ( ! V_10 ) {
memset ( V_11 -> V_22 , '\0' , V_23 ) ;
V_11 -> V_24 = 0 ;
} else {
memcpy ( V_11 -> V_22 , V_10 , V_23 ) ;
V_11 -> V_24 = 1 ;
}
V_12 = 0 ;
V_20:
F_12 ( V_11 ) ;
V_15:
return V_12 ;
}
void F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_3 , * V_25 ;
F_9 ( & V_4 ) ;
F_14 (r, tmp, &ipx_routes, node)
if ( V_3 -> V_21 == V_9 ) {
F_15 ( & V_3 -> V_10 ) ;
F_12 ( V_3 ) ;
}
F_11 ( & V_4 ) ;
}
static int F_16 ( struct V_26 * V_27 )
{
struct V_8 * V_9 ;
int V_12 = - V_28 ;
V_9 = F_17 ( V_27 -> V_29 ) ;
if ( ! V_9 )
goto V_15;
V_12 = F_6 ( V_27 -> V_30 , V_9 , V_27 -> V_31 ) ;
F_18 ( V_9 ) ;
V_15:
return V_12 ;
}
static int F_19 ( T_1 V_2 )
{
struct V_1 * V_3 , * V_25 ;
int V_12 ;
F_9 ( & V_4 ) ;
F_14 (r, tmp, &ipx_routes, node)
if ( V_3 -> V_5 == V_2 ) {
V_12 = - V_32 ;
if ( ! V_3 -> V_24 )
goto V_15;
F_15 ( & V_3 -> V_10 ) ;
F_12 ( V_3 ) ;
V_12 = 0 ;
goto V_15;
}
V_12 = - V_33 ;
V_15:
F_11 ( & V_4 ) ;
return V_12 ;
}
int F_20 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = F_21 ( V_35 ) ;
struct V_1 * V_3 = F_1 ( F_22 ( V_35 ) -> V_38 ) ;
if ( ! V_3 ) {
F_23 ( V_35 ) ;
return 0 ;
}
F_24 ( V_3 -> V_21 ) ;
F_25 ( V_3 -> V_21 , V_35 , V_3 -> V_24 ?
V_3 -> V_22 : V_37 -> V_39 . V_10 ) ;
F_18 ( V_3 -> V_21 ) ;
F_12 ( V_3 ) ;
return 0 ;
}
int F_26 ( struct V_40 * V_41 , struct V_42 * V_43 ,
struct V_44 * V_45 , T_2 V_46 , int V_47 )
{
struct V_34 * V_35 ;
struct V_48 * V_49 = F_27 ( V_41 ) ;
struct V_8 * V_9 ;
struct V_36 * V_37 ;
T_2 V_50 ;
int V_51 ;
struct V_1 * V_11 = NULL ;
int V_12 ;
if ( ! V_43 -> V_52 && V_53 ) {
V_43 -> V_52 = V_53 -> V_54 ;
V_9 = V_53 ;
} else {
V_11 = F_1 ( V_43 -> V_52 ) ;
V_12 = - V_28 ;
if ( ! V_11 )
goto V_15;
V_9 = V_11 -> V_21 ;
}
F_24 ( V_9 ) ;
V_51 = V_9 -> V_55 ;
V_50 = sizeof( struct V_36 ) + V_46 + V_51 ;
V_35 = F_28 ( V_41 , V_50 , V_47 , & V_12 ) ;
if ( ! V_35 )
goto V_20;
F_29 ( V_35 , V_51 ) ;
V_35 -> V_41 = V_41 ;
F_30 ( V_35 ) ;
F_31 ( V_35 ) ;
F_32 ( V_35 , sizeof( struct V_36 ) ) ;
V_37 = F_21 ( V_35 ) ;
V_37 -> V_56 = F_33 ( V_46 + sizeof( struct V_36 ) ) ;
F_22 ( V_35 ) -> V_57 = 0 ;
V_37 -> V_58 = V_43 -> V_59 ;
F_22 ( V_35 ) -> V_60 . V_61 = - 1 ;
#ifdef F_34
F_22 ( V_35 ) -> V_62 = V_49 -> V_9 -> V_54 ;
memcpy ( V_37 -> V_63 . V_10 , V_49 -> V_10 , V_23 ) ;
#else
V_12 = F_35 ( V_49 -> V_64 ) ;
if ( V_12 == 0x453 || V_12 == 0x452 ) {
F_22 ( V_35 ) -> V_62 = V_9 -> V_54 ;
memcpy ( V_37 -> V_63 . V_10 , V_9 -> V_65 , V_23 ) ;
} else {
F_22 ( V_35 ) -> V_62 = V_49 -> V_9 -> V_54 ;
memcpy ( V_37 -> V_63 . V_10 , V_49 -> V_9 -> V_65 ,
V_23 ) ;
}
#endif
V_37 -> V_63 . V_40 = V_49 -> V_64 ;
F_22 ( V_35 ) -> V_38 = V_43 -> V_52 ;
memcpy ( V_37 -> V_39 . V_10 , V_43 -> V_66 , V_23 ) ;
V_37 -> V_39 . V_40 = V_43 -> V_67 ;
V_12 = F_36 ( F_32 ( V_35 , V_46 ) , V_45 , V_46 ) ;
if ( V_12 ) {
F_23 ( V_35 ) ;
goto V_20;
}
if ( V_41 -> V_68 || V_9 -> V_69 == F_33 ( V_70 ) )
V_37 -> V_71 = F_33 ( 0xFFFF ) ;
else
V_37 -> V_71 = F_37 ( V_37 , V_46 + sizeof( struct V_36 ) ) ;
V_12 = F_25 ( V_9 , V_35 , ( V_11 && V_11 -> V_24 ) ?
V_11 -> V_22 : V_37 -> V_39 . V_10 ) ;
V_20:
F_18 ( V_9 ) ;
if ( V_11 )
F_12 ( V_11 ) ;
V_15:
return V_12 ;
}
int F_38 ( unsigned int V_72 , void T_3 * V_73 )
{
struct V_74 V_11 ;
struct V_42 * V_75 , * V_76 ;
int V_12 = - V_77 ;
if ( F_39 ( & V_11 , V_73 , sizeof( V_11 ) ) )
goto V_15;
V_75 = (struct V_42 * ) & V_11 . V_78 ;
V_76 = (struct V_42 * ) & V_11 . V_79 ;
V_12 = - V_80 ;
if ( ! ( V_11 . V_81 & V_82 ) ||
V_75 -> V_83 != V_84 ||
V_76 -> V_83 != V_84 )
goto V_15;
switch ( V_72 ) {
case V_85 :
V_12 = F_19 ( V_76 -> V_52 ) ;
break;
case V_86 : {
struct V_26 V_87 ;
V_87 . V_30 = V_76 -> V_52 ;
V_87 . V_29 = V_75 -> V_52 ;
memcpy ( V_87 . V_31 , V_75 -> V_66 , V_23 ) ;
V_12 = F_16 ( & V_87 ) ;
break;
}
}
V_15:
return V_12 ;
}
