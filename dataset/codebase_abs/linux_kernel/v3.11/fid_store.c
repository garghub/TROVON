static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = & V_3 -> V_5 ;
V_4 -> V_6 = & V_3 -> V_7 ;
V_4 -> V_8 = sizeof( V_3 -> V_7 ) ;
return V_4 ;
}
void F_2 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 ;
V_17 = F_3 ( V_14 , struct V_16 , V_18 ) ;
F_4 ( V_17 -> V_19 != NULL ) ;
V_17 -> V_19 -> V_20 = 0 ;
F_5 ( V_17 ) ;
}
int F_6 ( struct V_11 * V_12 , struct V_21 * V_22 )
{
struct V_16 * V_17 ;
struct V_13 * V_23 ;
int V_24 ;
F_7 ( V_17 ) ;
if ( V_17 == NULL )
return - V_25 ;
V_17 -> V_19 = V_22 ;
V_22 -> V_20 = 1 ;
V_23 = & V_17 -> V_18 ;
V_23 -> V_26 = F_2 ;
F_8 ( & V_23 -> V_27 ) ;
strncpy ( V_23 -> V_28 , L_1 , V_29 ) ;
V_23 -> V_28 [ V_29 - 1 ] = '\0' ;
V_24 = F_9 ( V_12 , V_23 ) ;
if ( V_24 )
F_5 ( V_17 ) ;
return V_24 ;
}
int F_10 ( const struct V_9 * V_10 , struct V_21 * V_22 ,
struct V_30 * V_31 , int V_32 )
{
struct V_33 * V_34 = F_11 ( V_22 -> V_35 -> V_36 . V_37 ) ;
struct V_2 * V_3 ;
struct V_11 * V_12 ;
T_1 V_38 = 0 ;
int V_24 ;
V_3 = F_12 ( & V_10 -> V_39 , & V_40 ) ;
F_4 ( V_3 != NULL ) ;
V_12 = F_13 ( V_10 , V_34 ) ;
if ( F_14 ( V_12 ) )
RETURN ( F_15 ( V_12 ) ) ;
V_24 = F_16 ( V_10 , V_22 -> V_35 ,
sizeof( struct V_30 ) , 0 , V_12 ) ;
if ( V_24 )
GOTO ( exit , V_24 ) ;
if ( V_31 != NULL ) {
V_24 = F_17 ( V_10 ,
V_22 -> V_41 -> V_42 ,
V_31 , V_12 ) ;
if ( V_24 )
GOTO ( exit , V_24 ) ;
}
V_24 = F_18 ( V_10 , V_34 , V_12 ) ;
if ( V_24 )
GOTO ( exit , V_24 ) ;
F_19 ( & V_3 -> V_7 , & V_22 -> V_43 ) ;
V_24 = F_20 ( V_10 , V_22 -> V_35 , F_1 ( V_3 ) , & V_38 , V_12 ) ;
if ( V_24 ) {
F_21 ( L_2 ,
V_22 -> V_44 , V_24 ) ;
GOTO ( exit , V_24 ) ;
} else if ( V_31 != NULL ) {
V_24 = F_22 ( V_10 , V_22 -> V_41 -> V_42 , V_31 ,
V_12 ) ;
if ( V_24 ) {
F_21 ( L_3 ,
V_22 -> V_44 , V_24 ) ;
GOTO ( exit , V_24 ) ;
}
}
if ( ! V_32 )
V_32 = ! ! F_6 ( V_12 , V_22 ) ;
V_12 -> V_45 |= V_32 ;
exit:
F_23 ( V_10 , V_34 , V_12 ) ;
return V_24 ;
}
int F_24 ( struct V_21 * V_22 ,
const struct V_9 * V_10 )
{
struct V_2 * V_3 ;
T_1 V_38 = 0 ;
int V_24 ;
V_46 ;
V_3 = F_12 ( & V_10 -> V_39 , & V_40 ) ;
F_4 ( V_3 != NULL ) ;
V_24 = V_22 -> V_35 -> V_47 -> V_48 ( V_10 , V_22 -> V_35 ,
F_1 ( V_3 ) ,
& V_38 , V_49 ) ;
if ( V_24 == sizeof( V_3 -> V_7 ) ) {
F_25 ( & V_22 -> V_43 , & V_3 -> V_7 ) ;
F_26 ( V_50 , L_4 V_51 L_5 ,
V_22 -> V_44 , F_27 ( & V_22 -> V_43 ) ) ;
V_24 = 0 ;
} else if ( V_24 == 0 ) {
V_24 = - V_52 ;
} else if ( V_24 > 0 ) {
F_21 ( L_6 , V_22 -> V_44 ,
V_24 , ( int ) sizeof( V_3 -> V_7 ) ) ;
V_24 = - V_53 ;
}
RETURN ( V_24 ) ;
}
int F_28 ( struct V_21 * V_22 ,
const struct V_9 * V_10 ,
struct V_33 * V_54 )
{
struct V_55 * V_56 ;
struct V_57 V_58 ;
struct V_59 V_60 ;
struct V_61 V_62 ;
const char * V_63 ;
int V_24 ;
V_46 ;
V_63 = V_22 -> V_64 == V_65 ?
V_66 : V_67 ;
if ( V_22 -> V_64 == V_65 )
F_29 ( & V_58 , V_68 ) ;
else
F_29 ( & V_58 , V_69 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_70 = V_71 ;
V_60 . V_72 = V_73 | 0666 ;
V_62 . V_74 = V_75 ;
V_56 = F_30 ( V_10 , V_54 , & V_58 , & V_62 , & V_60 ) ;
if ( ! F_14 ( V_56 ) ) {
V_22 -> V_35 = V_56 ;
V_24 = 0 ;
} else {
F_21 ( L_7 ,
V_22 -> V_44 , V_63 , ( int ) F_15 ( V_56 ) ) ;
V_24 = F_15 ( V_56 ) ;
}
RETURN ( V_24 ) ;
}
void F_31 ( struct V_21 * V_22 ,
const struct V_9 * V_10 )
{
V_46 ;
if ( V_22 -> V_35 != NULL ) {
if ( ! F_14 ( V_22 -> V_35 ) )
F_32 ( V_10 , & V_22 -> V_35 -> V_36 ) ;
V_22 -> V_35 = NULL ;
}
EXIT ;
}
