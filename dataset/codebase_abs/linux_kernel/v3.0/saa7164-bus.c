int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_2 ( & V_4 -> V_6 ) ;
V_4 -> Type = V_7 ;
V_4 -> V_8 = V_9 ;
V_4 -> V_10 = ( V_11 * ) ( V_2 -> V_12 +
( ( V_13 ) V_2 -> V_14 . V_15 ) ) ;
V_4 -> V_16 = V_17 ;
V_4 -> V_18 = ( V_11 * ) ( V_2 -> V_12 +
( ( V_13 ) V_2 -> V_14 . V_19 ) ) ;
V_4 -> V_20 = V_17 ;
V_4 -> V_21 = ( ( V_13 ) V_2 -> V_22 . V_23 ) +
( 2 * sizeof( V_24 ) ) ;
V_4 -> V_25 = V_4 -> V_21 + ( 1 * sizeof( V_13 ) ) ;
V_4 -> V_26 = V_4 -> V_21 + ( 2 * sizeof( V_13 ) ) ;
V_4 -> V_27 = V_4 -> V_21 + ( 3 * sizeof( V_13 ) ) ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_4 ( V_28 , L_1 ) ;
F_4 ( V_28 , L_2 , V_4 -> Type ) ;
F_4 ( V_28 , L_3 , V_2 -> V_12 ) ;
F_4 ( V_28 , L_4 , V_4 -> V_8 ) ;
F_4 ( V_28 , L_5 , V_4 -> V_10 ) ;
F_4 ( V_28 , L_6 , V_4 -> V_16 ) ;
F_4 ( V_28 , L_7 , V_4 -> V_18 ) ;
F_4 ( V_28 , L_8 , V_4 -> V_20 ) ;
F_4 ( V_28 , L_9 ,
V_4 -> V_25 , F_5 ( V_4 -> V_25 ) ) ;
F_4 ( V_28 , L_10 ,
V_4 -> V_21 , F_5 ( V_4 -> V_21 ) ) ;
F_4 ( V_28 , L_11 ,
V_4 -> V_27 , F_5 ( V_4 -> V_27 ) ) ;
F_4 ( V_28 , L_12 ,
V_4 -> V_26 , F_5 ( V_4 -> V_26 ) ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int V_29 = 0 ;
if ( F_5 ( V_4 -> V_25 ) > V_4 -> V_16 )
V_29 ++ ;
if ( F_5 ( V_4 -> V_21 ) > V_4 -> V_16 )
V_29 ++ ;
if ( F_5 ( V_4 -> V_27 ) > V_4 -> V_20 )
V_29 ++ ;
if ( F_5 ( V_4 -> V_26 ) > V_4 -> V_20 )
V_29 ++ ;
if ( V_29 ) {
V_30 = 0xffff ;
F_3 ( V_2 ) ;
V_30 = 1024 ;
F_7 () ;
}
}
void F_8 ( struct V_1 * V_2 , struct V_31 * V_32 ,
void * V_33 )
{
F_4 ( V_28 , L_13 ) ;
F_4 ( V_28 , L_14 , V_32 -> V_34 ) ;
F_4 ( V_28 , L_15 , V_32 -> V_35 ) ;
F_4 ( V_28 , L_16 , V_32 -> V_36 ) ;
F_4 ( V_28 , L_17 , V_32 -> V_37 ) ;
F_4 ( V_28 , L_18 , V_32 -> V_38 ) ;
F_4 ( V_28 , L_19 , V_32 -> V_39 ) ;
if ( V_33 )
F_4 ( V_28 , L_20 ) ;
}
int F_9 ( struct V_1 * V_2 , struct V_31 * V_40 ,
void * V_33 )
{
struct V_3 * V_5 = & V_2 -> V_5 ;
V_13 V_41 , V_42 , V_43 , V_44 , V_45 ;
V_13 V_46 , V_47 ;
int V_48 = V_49 ;
if ( ! V_40 ) {
F_10 ( V_50 L_21 , V_51 ) ;
return V_49 ;
}
F_4 ( V_28 , L_22 , V_51 ) ;
F_6 ( V_2 ) ;
V_40 -> V_36 = F_11 ( V_40 -> V_36 ) ;
V_40 -> V_37 = F_11 ( V_40 -> V_37 ) ;
V_40 -> V_38 = F_11 ( V_40 -> V_38 ) ;
if ( V_40 -> V_36 > V_2 -> V_5 . V_8 ) {
F_10 ( V_50 L_23 ,
V_51 ) ;
return V_49 ;
}
if ( ( V_40 -> V_36 > 0 ) && ( V_33 == NULL ) ) {
F_10 ( V_50 L_24 , V_51 ) ;
return V_49 ;
}
F_12 ( & V_5 -> V_6 ) ;
V_41 = sizeof( * V_40 ) + V_40 -> V_36 ;
V_42 = 0 ;
V_43 = V_52 ;
V_44 = F_13 ( F_5 ( V_5 -> V_25 ) ) ;
V_45 = F_13 ( F_5 ( V_5 -> V_21 ) ) ;
if ( V_44 > V_45 )
V_42 = V_44 - V_45 ;
else
V_42 = ( V_44 + V_5 -> V_16 ) - V_45 ;
F_4 ( V_28 , L_25 , V_51 ,
V_41 ) ;
F_4 ( V_28 , L_26 , V_51 ,
V_42 ) ;
F_4 ( V_28 , L_27 , V_51 , V_44 ) ;
F_4 ( V_28 , L_28 , V_51 , V_45 ) ;
while ( V_41 >= V_42 ) {
if ( V_43 -- == 0 ) {
F_10 ( V_50 L_29 , V_51 ) ;
V_48 = V_53 ;
goto V_54;
}
F_14 ( 1 ) ;
V_44 = F_13 ( F_5 ( V_5 -> V_25 ) ) ;
if ( V_44 > V_45 )
V_42 = V_44 - V_45 ;
else
V_42 = ( V_44 + V_5 -> V_16 ) -
V_45 ;
}
V_46 = V_45 + V_41 ;
F_4 ( V_28 , L_30 , V_51 , V_46 ) ;
F_4 ( V_28 , L_31 , V_51 ,
V_5 -> V_16 ) ;
if ( V_46 > V_5 -> V_16 ) {
V_46 -= V_5 -> V_16 ;
V_47 = V_5 -> V_16 - V_45 ;
F_4 ( V_28 , L_32 , V_51 ,
V_47 ) ;
F_4 ( V_28 , L_33 , V_51 ,
( V_13 ) sizeof( * V_40 ) ) ;
if ( V_47 < sizeof( * V_40 ) ) {
F_4 ( V_28 , L_34 , V_51 ) ;
memcpy ( V_5 -> V_10 + V_45 , V_40 , V_47 ) ;
memcpy ( V_5 -> V_10 , ( V_11 * ) V_40 + V_47 ,
sizeof( * V_40 ) - V_47 ) ;
memcpy ( V_5 -> V_10 + sizeof( * V_40 ) - V_47 ,
V_33 , V_40 -> V_36 ) ;
} else if ( V_47 == sizeof( * V_40 ) ) {
F_4 ( V_28 , L_35 , V_51 ) ;
memcpy ( V_5 -> V_10 + V_45 , V_40 , sizeof( * V_40 ) ) ;
memcpy ( V_5 -> V_10 , V_33 , V_40 -> V_36 ) ;
} else {
memcpy ( V_5 -> V_10 + V_45 , V_40 , sizeof( * V_40 ) ) ;
if ( V_40 -> V_36 > 0 ) {
memcpy ( V_5 -> V_10 + V_45 +
sizeof( * V_40 ) , V_33 , V_47 -
sizeof( * V_40 ) ) ;
memcpy ( V_5 -> V_10 , ( V_11 * ) V_33 +
V_47 - sizeof( * V_40 ) ,
V_41 - V_47 ) ;
}
}
}
else {
F_4 ( V_28 , L_36 , V_51 ) ;
memcpy ( V_5 -> V_10 + V_45 , V_40 , sizeof( * V_40 ) ) ;
memcpy ( V_5 -> V_10 + V_45 + sizeof( * V_40 ) , V_33 ,
V_40 -> V_36 ) ;
}
F_4 ( V_28 , L_30 , V_51 , V_46 ) ;
F_15 ( V_5 -> V_21 , F_16 ( V_46 ) ) ;
V_48 = V_55 ;
V_54:
F_3 ( V_2 ) ;
F_17 ( & V_5 -> V_6 ) ;
F_6 ( V_2 ) ;
return V_48 ;
}
int F_18 ( struct V_1 * V_2 , struct V_31 * V_40 ,
void * V_33 , int V_56 )
{
struct V_3 * V_5 = & V_2 -> V_5 ;
V_13 V_57 , V_58 , V_59 , V_60 ,
V_61 , V_62 , V_47 ;
struct V_31 V_63 ;
int V_48 = V_49 ;
F_6 ( V_2 ) ;
if ( V_40 == NULL )
return V_48 ;
if ( V_40 -> V_36 > V_2 -> V_5 . V_8 ) {
F_10 ( V_50 L_23 ,
V_51 ) ;
return V_48 ;
}
if ( ( V_56 == 0 ) && ( V_40 -> V_36 > 0 ) && ( V_33 == NULL ) ) {
F_10 ( V_50
L_37 ,
V_51 , V_40 -> V_36 ) ;
return V_48 ;
}
F_12 ( & V_5 -> V_6 ) ;
V_60 = F_13 ( F_5 ( V_5 -> V_26 ) ) ;
V_59 = F_13 ( F_5 ( V_5 -> V_27 ) ) ;
if ( V_60 == V_59 ) {
V_48 = V_64 ;
goto V_54;
}
V_57 = sizeof( * V_40 ) ;
V_58 = 0 ;
if ( V_60 >= V_59 )
V_58 = V_60 - V_59 ;
else
V_58 = V_60 + V_5 -> V_20 - V_59 ;
if ( V_57 > V_58 ) {
F_10 ( V_50 L_38 , V_51 ) ;
V_48 = V_65 ;
goto V_54;
}
V_61 = V_59 + V_57 ;
if ( V_61 > V_5 -> V_20 ) {
V_61 -= V_5 -> V_20 ;
V_47 = V_5 -> V_20 - V_59 ;
memcpy ( & V_63 , V_5 -> V_18 + V_59 , V_47 ) ;
memcpy ( ( V_11 * ) & V_63 + V_47 , V_5 -> V_18 ,
V_57 - V_47 ) ;
} else {
memcpy ( & V_63 , V_5 -> V_18 + V_59 , V_57 ) ;
}
if ( V_56 ) {
memcpy ( V_40 , & V_63 , sizeof( * V_40 ) ) ;
goto V_66;
}
if ( ( V_63 . V_34 != V_40 -> V_34 ) || ( V_63 . V_37 != V_40 -> V_37 ) ||
( V_63 . V_38 != V_40 -> V_38 ) ||
( V_63 . V_39 != V_40 -> V_39 ) || ( V_63 . V_36 != V_40 -> V_36 ) ) {
F_10 ( V_50 L_39 , V_51 ) ;
F_8 ( V_2 , V_40 , V_33 ) ;
F_8 ( V_2 , & V_63 , NULL ) ;
V_48 = V_65 ;
goto V_54;
}
V_62 = V_40 -> V_36 ;
V_57 = sizeof( * V_40 ) + V_40 -> V_36 ;
V_58 = 0 ;
if ( V_60 >= V_59 )
V_58 = V_60 - V_59 ;
else
V_58 = V_60 + V_5 -> V_20 - V_59 ;
if ( V_57 > V_58 ) {
F_10 ( V_50 L_40
L_41 , V_51 ) ;
V_48 = V_65 ;
goto V_54;
}
V_61 = V_59 + V_57 ;
if ( V_61 > V_5 -> V_20 ) {
V_61 -= V_5 -> V_20 ;
V_47 = V_5 -> V_20 - V_59 ;
if ( V_47 < sizeof( * V_40 ) ) {
memcpy ( V_40 , V_5 -> V_18 + V_59 , V_47 ) ;
memcpy ( ( V_11 * ) V_40 + V_47 , V_5 -> V_18 ,
sizeof( * V_40 ) - V_47 ) ;
if ( V_33 )
memcpy ( V_33 , V_5 -> V_18 + sizeof( * V_40 ) -
V_47 , V_62 ) ;
} else if ( V_47 == sizeof( * V_40 ) ) {
memcpy ( V_40 , V_5 -> V_18 + V_59 , sizeof( * V_40 ) ) ;
if ( V_33 )
memcpy ( V_33 , V_5 -> V_18 , V_62 ) ;
} else {
memcpy ( V_40 , V_5 -> V_18 + V_59 , sizeof( * V_40 ) ) ;
if ( V_33 ) {
memcpy ( V_33 , V_5 -> V_18 + V_59 +
sizeof( * V_40 ) , V_47 - sizeof( * V_40 ) ) ;
memcpy ( V_33 + V_47 - sizeof( * V_40 ) ,
V_5 -> V_18 , V_57 -
V_47 ) ;
}
}
} else {
memcpy ( V_40 , V_5 -> V_18 + V_59 , sizeof( * V_40 ) ) ;
if ( V_33 )
memcpy ( V_33 , V_5 -> V_18 + V_59 + sizeof( * V_40 ) ,
V_62 ) ;
}
F_15 ( V_5 -> V_27 , F_16 ( V_61 ) ) ;
V_66:
V_40 -> V_36 = F_19 ( V_40 -> V_36 ) ;
V_40 -> V_37 = F_19 ( V_40 -> V_37 ) ;
V_40 -> V_38 = F_19 ( V_40 -> V_38 ) ;
V_48 = V_55 ;
V_54:
F_17 ( & V_5 -> V_6 ) ;
F_6 ( V_2 ) ;
return V_48 ;
}
