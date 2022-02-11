const struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
unsigned int * V_5 , int V_6 )
{
const struct V_7 * V_8 = F_2 ( V_3 ) ;
T_1 V_9 ;
T_2 V_10 ;
int V_11 ;
V_9 = V_8 -> V_12 ;
V_11 = F_3 ( V_3 , ( ( T_1 * ) ( V_8 + 1 ) - V_3 -> V_13 ) ,
& V_9 , & V_10 ) ;
if ( ( V_11 < 0 ) || ( V_11 > V_3 -> V_14 ) ) {
F_4 ( L_1 ) ;
return NULL ;
}
* V_5 = V_3 -> V_14 - V_11 ;
if ( V_9 != V_15 || * V_5 < sizeof( struct V_1 ) ) {
F_4 ( L_2 ,
V_9 , * V_5 ) ;
return NULL ;
}
V_4 = F_5 ( V_3 , V_11 , sizeof( struct V_1 ) ,
V_4 ) ;
if ( V_4 == NULL )
return NULL ;
if ( V_4 -> V_16 ) {
F_4 ( L_3 ) ;
return NULL ;
}
if ( F_6 ( V_3 , V_6 , V_11 , V_15 ) ) {
F_4 ( L_4 ) ;
return NULL ;
}
return V_4 ;
}
struct V_7 * F_7 ( struct V_2 * V_17 ,
const struct V_2 * V_3 ,
T_3 V_18 , int V_19 )
{
struct V_7 * V_20 ;
const struct V_7 * V_8 = F_2 ( V_3 ) ;
#define F_8 0x0U
const T_3 V_21 = F_8 ;
F_9 ( V_17 , sizeof( struct V_7 ) ) ;
F_10 ( V_17 ) ;
V_20 = F_2 ( V_17 ) ;
F_11 ( V_20 , V_21 , 0 ) ;
V_20 -> V_22 = V_19 ;
V_20 -> V_12 = V_18 ;
V_20 -> V_23 = V_8 -> V_24 ;
V_20 -> V_24 = V_8 -> V_23 ;
V_17 -> V_18 = F_12 ( V_25 ) ;
return V_20 ;
}
void F_13 ( struct V_2 * V_17 ,
const struct V_2 * V_3 ,
const struct V_1 * V_26 , unsigned int V_5 )
{
struct V_1 * V_27 ;
int V_28 ;
F_14 ( V_17 ) ;
V_27 = F_9 ( V_17 , sizeof( struct V_1 ) ) ;
V_27 -> V_29 = sizeof( struct V_1 ) / 4 ;
V_27 -> V_30 = V_26 -> V_31 ;
V_27 -> V_31 = V_26 -> V_30 ;
if ( V_26 -> V_32 ) {
V_28 = 0 ;
V_27 -> V_33 = V_26 -> V_34 ;
V_27 -> V_34 = 0 ;
} else {
V_28 = 1 ;
V_27 -> V_34 = F_15 ( F_16 ( V_26 -> V_33 ) + V_26 -> V_35 + V_26 -> V_36 +
V_5 - ( V_26 -> V_29 << 2 ) ) ;
V_27 -> V_33 = 0 ;
}
( ( V_37 * ) V_27 ) [ 13 ] = 0 ;
V_27 -> V_16 = 1 ;
V_27 -> V_32 = V_28 ;
V_27 -> V_38 = 0 ;
V_27 -> V_39 = 0 ;
V_27 -> V_40 = 0 ;
V_27 -> V_40 = F_17 ( & F_2 ( V_17 ) -> V_23 ,
& F_2 ( V_17 ) -> V_24 ,
sizeof( struct V_1 ) , V_15 ,
F_18 ( V_27 ,
sizeof( struct V_1 ) , 0 ) ) ;
}
void F_19 ( struct V_41 * V_41 , struct V_2 * V_3 , int V_6 )
{
struct V_2 * V_17 ;
struct V_1 V_42 ;
const struct V_1 * V_4 ;
unsigned int V_5 , V_43 ;
const struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_7 * V_20 ;
struct V_44 * V_45 = NULL ;
struct V_46 V_47 ;
if ( ( ! ( F_20 ( & V_8 -> V_23 ) & V_48 ) ) ||
( ! ( F_20 ( & V_8 -> V_24 ) & V_48 ) ) ) {
F_4 ( L_5 ) ;
return;
}
V_4 = F_1 ( V_3 , & V_42 , & V_5 , V_6 ) ;
if ( ! V_4 )
return;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_49 = V_15 ;
V_47 . V_23 = V_8 -> V_24 ;
V_47 . V_24 = V_8 -> V_23 ;
V_47 . V_50 = V_4 -> V_31 ;
V_47 . V_51 = V_4 -> V_30 ;
V_47 . V_52 = F_21 ( F_22 ( V_3 ) -> V_53 ) ;
V_47 . V_54 = F_23 ( V_41 , V_3 -> V_55 ) ;
F_24 ( V_3 , F_25 ( & V_47 ) ) ;
V_45 = F_26 ( V_41 , NULL , & V_47 ) ;
if ( V_45 -> error ) {
F_27 ( V_45 ) ;
return;
}
V_45 = F_28 ( V_41 , V_45 , F_25 ( & V_47 ) , NULL , 0 ) ;
if ( F_29 ( V_45 ) )
return;
V_43 = ( V_45 -> V_53 -> V_56 + 15 ) & ~ 15 ;
V_17 = F_30 ( V_43 + 15 + V_45 -> V_57 + sizeof( struct V_7 )
+ sizeof( struct V_1 ) + V_45 -> V_58 ,
V_59 ) ;
if ( ! V_17 ) {
F_31 ( L_6 ) ;
F_27 ( V_45 ) ;
return;
}
F_32 ( V_17 , V_45 ) ;
V_17 -> V_55 = V_47 . V_54 ;
F_33 ( V_17 , V_43 + V_45 -> V_57 ) ;
V_20 = F_7 ( V_17 , V_3 , V_15 ,
F_34 ( V_45 ) ) ;
F_13 ( V_17 , V_3 , V_4 , V_5 ) ;
F_35 ( V_17 , V_3 ) ;
#if F_36 ( V_60 )
if ( V_3 -> V_61 ) {
struct V_62 * V_63 = F_37 ( V_3 ) ;
V_17 -> V_53 = F_38 ( V_3 ) ;
V_17 -> V_18 = F_12 ( V_25 ) ;
V_20 -> V_64 = F_12 ( sizeof( struct V_1 ) ) ;
if ( F_39 ( V_17 , V_17 -> V_53 , F_40 ( V_17 -> V_18 ) ,
V_63 -> V_65 , V_63 -> V_66 , V_17 -> V_14 ) < 0 )
return;
F_41 ( V_17 ) ;
} else
#endif
F_42 ( V_41 , V_17 -> V_67 , V_17 ) ;
}
static bool F_43 ( struct V_2 * V_68 , int V_6 )
{
const struct V_7 * V_20 = F_2 ( V_68 ) ;
int V_69 ;
T_2 V_70 ;
T_1 V_9 ;
if ( F_44 ( V_68 ) )
return true ;
V_9 = V_20 -> V_12 ;
V_69 = F_3 ( V_68 , ( ( T_1 * ) ( V_20 + 1 ) - V_68 -> V_13 ) , & V_9 , & V_70 ) ;
if ( V_69 < 0 || V_69 >= V_68 -> V_14 || ( V_70 & F_12 ( ~ 0x7 ) ) != 0 )
return false ;
return F_6 ( V_68 , V_6 , V_69 , V_9 ) == 0 ;
}
void F_45 ( struct V_41 * V_41 , struct V_2 * V_71 ,
unsigned char V_72 , unsigned int V_73 )
{
if ( ! F_43 ( V_71 , V_73 ) )
return;
if ( V_73 == V_74 && V_71 -> V_53 == NULL )
V_71 -> V_53 = V_41 -> V_75 ;
F_46 ( V_71 , V_76 , V_72 , 0 ) ;
}
