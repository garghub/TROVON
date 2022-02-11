int F_1 ( struct V_1 * V_2 , int V_3 ,
enum V_4 V_5 , T_1 * V_6 )
{
int V_7 = F_2 ( V_5 ) ;
int V_8 , V_9 ;
struct V_10 V_11 ;
if ( V_5 == V_12 ) {
* V_6 = 0 ;
return 0 ;
}
if ( F_3 ( V_7 < 0 ) ) {
F_4 ( & V_2 -> V_13 , L_1 ,
V_5 ) ;
return - V_14 ;
}
V_9 = F_5 ( & V_2 -> V_13 , V_3 , & V_11 ) ;
if ( F_3 ( V_9 < 0 ) ) {
F_4 ( & V_2 -> V_13 , L_2 , V_9 ) ;
return V_9 ;
}
V_8 = F_6 ( V_11 . V_15 ) * V_11 . V_16 ;
if ( V_7 >= V_8 )
* V_6 = 0 ;
else
* V_6 = ( ( V_8 + ( V_7 >> 1 ) ) / V_7 ) - 1 ;
return 0 ;
}
struct V_17 * F_7 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
int V_9 ;
struct V_22 * V_23 ;
struct V_1 * V_2 = F_8 ( V_19 -> V_24 , struct V_1 ,
V_13 ) ;
V_23 = F_9 ( V_25 , V_26 ) ;
if ( ! V_23 ) {
F_4 ( V_19 -> V_24 , L_3 ,
V_19 , V_21 ) ;
return F_10 ( - V_27 ) ;
}
V_23 -> V_23 . V_28 = V_21 -> V_28 ;
V_23 -> V_23 . V_29 = V_21 -> V_29 ;
V_23 -> V_23 . V_30 = V_21 -> V_31 ;
if ( V_32 < 0 ) {
T_1 V_6 ;
if ( F_1 ( V_2 , V_21 -> V_33 ,
V_21 -> V_34 , & V_6 ) ) {
V_9 = - V_14 ;
goto V_35;
}
V_23 -> V_23 . V_6 = V_6 ;
} else
V_23 -> V_23 . V_6 = V_32 ;
V_23 -> V_23 . V_36 = V_21 -> V_37 ;
V_23 -> V_23 . V_38 . V_39 = F_11 ( V_40 , 6 ) ;
V_23 -> V_23 . V_38 . V_39 |= F_11 ( V_41 ,
V_21 -> V_38 . V_42 ) ;
V_23 -> V_23 . V_38 . V_39 |= F_11 ( V_43 ,
V_21 -> V_38 . V_44 ) ;
V_23 -> V_23 . V_38 . V_39 |= F_11 ( V_45 ,
V_21 -> V_38 . V_46 ) ;
V_23 -> V_23 . V_38 . V_39 |= F_11 ( V_47 , 0x1B ) ;
if ( V_21 -> V_37 & V_48 ) {
int V_49 ;
struct V_10 V_50 ;
union V_51 V_52 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_49 = F_5 ( V_19 -> V_24 , V_21 -> V_33 ,
& V_50 ) ;
if ( V_49 ) {
V_9 = - V_14 ;
F_4 ( V_19 -> V_24 , L_4
L_5
L_6 , V_49 , V_19 , V_21 ) ;
goto V_35;
}
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_49 = F_12 ( V_19 -> V_24 ,
V_21 -> V_33 ,
V_21 -> V_38 . V_53 , & V_52 ) ;
if ( V_49 ) {
V_9 = - V_14 ;
F_4 ( V_19 -> V_24 , L_7
L_8
L_6 , V_49 , V_19 , V_21 ) ;
goto V_35;
}
memcpy ( & V_23 -> V_23 . V_38 . V_54 , & V_52 , sizeof( V_52 ) ) ;
}
V_23 -> V_23 . V_55 = V_2 -> V_56 ;
memcpy ( & V_23 -> V_23 . V_38 . V_57 , & V_21 -> V_38 . V_58 ,
sizeof( V_21 -> V_38 . V_58 ) ) ;
return & V_23 -> V_17 ;
V_35:
F_13 ( V_25 , V_23 ) ;
return F_10 ( V_9 ) ;
}
int F_14 ( struct V_17 * V_59 , struct V_20 * V_21 )
{
struct V_22 * V_23 ;
struct V_60 V_61 ;
struct V_1 * V_2 = F_8 ( V_59 -> V_19 -> V_24 , struct V_1 ,
V_13 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_28 = V_21 -> V_28 ;
V_61 . V_29 = V_21 -> V_29 ;
V_61 . V_30 = V_21 -> V_31 ;
V_61 . V_6 = V_21 -> V_34 ;
V_61 . V_36 = F_11 ( V_62 ,
( V_21 -> V_37 & V_48 ) > 0 ) ;
V_61 . V_38 . V_39 = F_11 ( V_41 ,
V_21 -> V_38 . V_42 ) ;
V_61 . V_38 . V_39 |= F_11 ( V_43 ,
V_21 -> V_38 . V_44 ) ;
V_61 . V_38 . V_39 |= F_11 ( V_45 ,
V_21 -> V_38 . V_46 ) ;
V_61 . V_38 . V_39 |= F_11 ( V_47 , 0x1b ) ;
if ( V_21 -> V_37 & V_48 ) {
int V_49 ;
struct V_10 V_50 ;
union V_51 V_52 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_49 = F_5 ( V_59 -> V_24 , V_21 -> V_33 ,
& V_50 ) ;
if ( V_49 ) {
F_4 ( V_59 -> V_24 , L_4
L_5
L_9 ,
V_49 , V_59 , V_21 , V_21 -> V_33 ) ;
return - V_14 ;
}
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_49 = F_12 ( V_59 -> V_24 ,
V_21 -> V_33 ,
V_21 -> V_38 . V_53 , & V_52 ) ;
if ( V_49 ) {
F_4 ( V_59 -> V_24 , L_7
L_8
L_10
L_11 ,
V_49 , V_59 , V_21 , V_21 -> V_33 ,
V_21 -> V_38 . V_53 ) ;
return - V_14 ;
}
memcpy ( & V_61 . V_38 . V_54 , & V_52 , sizeof( V_52 ) ) ;
}
V_61 . V_55 = V_2 -> V_56 ;
memcpy ( & V_61 . V_38 . V_57 , & V_21 -> V_38 . V_58 ,
sizeof( V_21 -> V_38 . V_58 ) ) ;
V_23 = F_8 ( V_59 , struct V_22 , V_17 ) ;
V_23 -> V_23 = V_61 ;
return 0 ;
}
int F_15 ( struct V_17 * V_59 , struct V_20 * V_21 )
{
struct V_22 * V_23 = F_8 ( V_59 , struct V_22 , V_17 ) ;
memcpy ( & V_21 -> V_38 . V_58 , & V_23 -> V_23 . V_38 . V_57 ,
sizeof( V_21 -> V_38 . V_58 ) ) ;
V_21 -> V_28 = V_23 -> V_23 . V_28 ;
V_21 -> V_29 = V_23 -> V_23 . V_29 ;
V_21 -> V_31 = V_23 -> V_23 . V_30 ;
V_21 -> V_34 = V_23 -> V_23 . V_6 ;
V_21 -> V_37 = F_16 ( V_62 , V_23 -> V_23 . V_36 ) ;
V_21 -> V_38 . V_42 = F_16 ( V_41 ,
V_23 -> V_23 . V_38 . V_39 ) ;
V_21 -> V_38 . V_46 = F_16 ( V_45 ,
V_23 -> V_23 . V_38 . V_39 ) ;
V_21 -> V_38 . V_44 = F_16 ( V_43 ,
V_23 -> V_23 . V_38 . V_39 ) ;
return 0 ;
}
int F_17 ( struct V_17 * V_59 )
{
F_13 ( V_25 , F_8 ( V_59 , struct V_22 , V_17 ) ) ;
return 0 ;
}
int F_18 ( void )
{
V_25 = F_19 ( L_12 ,
sizeof( struct V_22 ) , 0 ,
V_63 ,
NULL ) ;
if ( ! V_25 )
return - V_27 ;
return 0 ;
}
void F_20 ( void )
{
if ( V_25 )
F_21 ( V_25 ) ;
}
