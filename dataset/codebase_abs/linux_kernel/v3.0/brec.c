T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
T_2 V_5 [ 2 ] ;
T_1 V_6 ;
V_6 = V_2 -> V_7 -> V_8 - ( V_3 + 2 ) * 2 ;
F_2 ( V_2 , V_5 , V_6 , 4 ) ;
* V_4 = F_3 ( V_5 [ 1 ] ) ;
return F_3 ( V_5 [ 0 ] ) - * V_4 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_5 , V_9 ;
if ( V_2 -> type != V_10 && V_2 -> type != V_11 )
return 0 ;
if ( ( V_2 -> type == V_10 ) &&
! ( V_2 -> V_7 -> V_12 & V_13 ) ) {
if ( V_2 -> V_7 -> V_12 & V_14 )
V_5 = V_2 -> V_7 -> V_15 + 2 ;
else
V_5 = V_2 -> V_7 -> V_15 + 1 ;
} else {
V_9 = F_5 ( V_2 , V_2 -> V_7 -> V_8 - ( V_3 + 1 ) * 2 ) ;
if ( ! V_9 )
return 0 ;
if ( V_2 -> V_7 -> V_12 & V_14 ) {
V_5 = F_5 ( V_2 , V_9 ) + 2 ;
if ( V_5 > V_2 -> V_7 -> V_15 + 2 ) {
F_6 ( V_16 L_1 ,
V_5 ) ;
V_5 = 0 ;
}
} else {
V_5 = ( F_7 ( V_2 , V_9 ) | 1 ) + 1 ;
if ( V_5 > V_2 -> V_7 -> V_15 + 1 ) {
F_6 ( V_16 L_1 ,
V_5 ) ;
V_5 = 0 ;
}
}
}
return V_5 ;
}
int F_8 ( struct V_17 * V_18 , void * V_19 , int V_20 )
{
struct V_21 * V_7 ;
struct V_1 * V_2 , * V_22 ;
int V_23 , V_24 , V_3 ;
int V_25 , V_26 ;
int V_27 , V_28 , V_29 ;
T_3 V_30 ;
V_7 = V_18 -> V_7 ;
if ( ! V_18 -> V_31 ) {
if ( ! V_7 -> V_32 )
F_9 ( V_7 ) ;
V_18 -> V_31 = F_10 ( V_7 , V_7 -> V_33 ) ;
if ( F_11 ( V_18 -> V_31 ) )
return F_12 ( V_18 -> V_31 ) ;
V_18 -> V_34 = - 1 ;
}
V_22 = NULL ;
V_24 = ( V_18 -> V_35 -> V_24 | 1 ) + 1 ;
V_36:
V_3 = V_18 -> V_34 + 1 ;
V_23 = V_24 + V_20 ;
V_2 = V_18 -> V_31 ;
F_13 ( V_2 ) ;
V_29 = V_7 -> V_8 - ( V_2 -> V_37 + 1 ) * 2 ;
V_26 = F_5 ( V_2 , V_29 ) ;
V_29 -= 2 ;
F_14 ( V_38 , L_2 , V_3 , V_23 , V_26 , V_29 ) ;
if ( V_23 > V_29 - V_26 ) {
if ( V_22 )
F_15 ( L_3 ) ;
V_22 = F_16 ( V_18 ) ;
if ( F_11 ( V_22 ) )
return F_12 ( V_22 ) ;
goto V_36;
}
if ( V_2 -> type == V_11 ) {
V_7 -> V_39 ++ ;
F_17 ( V_7 -> V_40 ) ;
}
V_2 -> V_37 ++ ;
F_18 ( V_2 , F_19 ( struct V_41 , V_37 ) , V_2 -> V_37 ) ;
F_18 ( V_2 , V_29 , V_26 + V_23 ) ;
V_25 = V_26 ;
V_28 = V_29 + 2 ;
V_27 = V_7 -> V_8 - ( V_3 + 1 ) * 2 ;
if ( V_27 == V_28 )
goto V_42;
do {
V_25 = F_5 ( V_2 , V_28 + 2 ) ;
F_18 ( V_2 , V_28 , V_25 + V_23 ) ;
V_28 += 2 ;
} while ( V_28 < V_27 );
F_20 ( V_2 , V_25 + V_23 , V_25 ,
V_26 - V_25 ) ;
V_42:
F_21 ( V_2 , V_18 -> V_35 , V_25 , V_24 ) ;
F_21 ( V_2 , V_19 , V_25 + V_24 , V_20 ) ;
F_13 ( V_2 ) ;
if ( V_22 ) {
if ( ! V_3 && V_22 != V_2 )
F_22 ( V_18 ) ;
F_23 ( V_18 -> V_31 ) ;
if ( ! V_22 -> V_43 ) {
F_9 ( V_7 ) ;
V_22 -> V_43 = V_7 -> V_32 ;
}
V_18 -> V_31 = F_10 ( V_7 , V_22 -> V_43 ) ;
V_30 = F_24 ( V_22 -> V_44 ) ;
V_19 = & V_30 ;
V_20 = sizeof( V_30 ) ;
F_25 ( V_22 , V_18 -> V_35 , 14 ) ;
F_26 ( V_18 -> V_31 , V_18 ) ;
F_23 ( V_22 ) ;
V_22 = NULL ;
if ( V_7 -> V_12 & V_13 )
V_24 = V_18 -> V_35 -> V_24 + 1 ;
else {
V_18 -> V_35 -> V_24 = V_7 -> V_15 ;
V_24 = V_7 -> V_15 + 1 ;
}
goto V_36;
}
if ( ! V_3 )
F_22 ( V_18 ) ;
return 0 ;
}
int F_27 ( struct V_17 * V_18 )
{
struct V_21 * V_7 ;
struct V_1 * V_2 , * V_43 ;
int V_26 , V_45 , V_25 , V_23 ;
V_7 = V_18 -> V_7 ;
V_2 = V_18 -> V_31 ;
V_36:
V_45 = V_7 -> V_8 - ( V_18 -> V_34 + 2 ) * 2 ;
V_26 = V_7 -> V_8 - ( V_2 -> V_37 + 1 ) * 2 ;
if ( V_2 -> type == V_11 ) {
V_7 -> V_39 -- ;
F_17 ( V_7 -> V_40 ) ;
}
F_13 ( V_2 ) ;
F_14 ( V_38 , L_4 , V_18 -> V_34 , V_18 -> V_46 + V_18 -> V_47 ) ;
if ( ! -- V_2 -> V_37 ) {
F_28 ( V_2 ) ;
if ( ! V_2 -> V_43 )
return 0 ;
V_43 = F_10 ( V_7 , V_2 -> V_43 ) ;
if ( F_11 ( V_43 ) )
return F_12 ( V_43 ) ;
F_23 ( V_2 ) ;
V_2 = V_18 -> V_31 = V_43 ;
F_26 ( V_2 , V_18 ) ;
goto V_36;
}
F_18 ( V_2 , F_19 ( struct V_41 , V_37 ) , V_2 -> V_37 ) ;
if ( V_45 == V_26 )
goto V_42;
V_23 = V_18 -> V_46 + V_18 -> V_47 ;
do {
V_25 = F_5 ( V_2 , V_45 ) ;
F_18 ( V_2 , V_45 + 2 , V_25 - V_23 ) ;
V_45 -= 2 ;
} while ( V_45 >= V_26 );
F_20 ( V_2 , V_18 -> V_48 , V_18 -> V_48 + V_23 ,
V_25 - V_18 -> V_48 - V_23 ) ;
V_42:
F_13 ( V_2 ) ;
if ( ! V_18 -> V_34 )
F_22 ( V_18 ) ;
return 0 ;
}
static struct V_1 * F_16 ( struct V_17 * V_18 )
{
struct V_21 * V_7 ;
struct V_1 * V_2 , * V_22 , * V_49 ;
struct V_41 V_50 ;
int V_37 , V_51 , V_52 , V_53 ;
int V_54 , V_55 , V_23 ;
V_7 = V_18 -> V_7 ;
V_2 = V_18 -> V_31 ;
V_22 = F_29 ( V_7 ) ;
if ( F_11 ( V_22 ) )
return V_22 ;
F_30 ( V_2 ) ;
F_14 ( V_38 , L_5 ,
V_2 -> V_44 , V_22 -> V_44 , V_2 -> V_56 ) ;
V_22 -> V_56 = V_2 -> V_56 ;
V_22 -> V_57 = V_2 -> V_44 ;
V_22 -> V_43 = V_2 -> V_43 ;
V_22 -> type = V_2 -> type ;
V_22 -> V_58 = V_2 -> V_58 ;
if ( V_2 -> V_56 )
V_49 = F_10 ( V_7 , V_2 -> V_56 ) ;
else
V_49 = NULL ;
if ( F_11 ( V_49 ) ) {
F_23 ( V_2 ) ;
F_23 ( V_22 ) ;
return V_49 ;
}
V_23 = V_7 -> V_8 / 2 - V_2 -> V_37 * 2 - 14 ;
V_53 = V_7 -> V_8 - 4 ;
V_37 = 1 ;
for (; ; ) {
V_54 = F_5 ( V_2 , V_53 ) ;
if ( V_54 > V_23 )
break;
V_53 -= 2 ;
if ( ++ V_37 < V_2 -> V_37 )
continue;
F_23 ( V_2 ) ;
F_23 ( V_22 ) ;
if ( V_49 )
F_23 ( V_49 ) ;
return F_31 ( - V_59 ) ;
}
if ( V_18 -> V_34 + 1 < V_37 ) {
V_53 += 2 ;
V_37 -- ;
V_54 = F_5 ( V_2 , V_53 ) ;
} else {
F_23 ( V_2 ) ;
F_30 ( V_22 ) ;
V_18 -> V_31 = V_22 ;
V_18 -> V_34 -= V_37 ;
V_18 -> V_48 -= V_54 - 14 ;
V_18 -> V_60 -= V_54 - 14 ;
}
V_22 -> V_37 = V_2 -> V_37 - V_37 ;
V_2 -> V_37 = V_37 ;
V_51 = V_7 -> V_8 - 2 ;
V_52 = 14 ;
V_23 = V_54 - V_52 ;
V_37 = V_22 -> V_37 ;
V_55 = V_54 ;
while ( V_37 ) {
F_18 ( V_22 , V_51 , V_52 ) ;
V_53 -= 2 ;
V_51 -= 2 ;
V_55 = F_5 ( V_2 , V_53 ) ;
V_52 = V_55 - V_23 ;
V_37 -- ;
}
F_18 ( V_22 , V_51 , V_52 ) ;
F_32 ( V_22 , 14 , V_2 , V_54 , V_55 - V_54 ) ;
V_50 . V_56 = F_24 ( V_22 -> V_56 ) ;
V_50 . V_57 = F_24 ( V_22 -> V_57 ) ;
V_50 . type = V_22 -> type ;
V_50 . V_58 = V_22 -> V_58 ;
V_50 . V_37 = F_33 ( V_22 -> V_37 ) ;
V_50 . V_61 = 0 ;
F_21 ( V_22 , & V_50 , 0 , sizeof( V_50 ) ) ;
V_2 -> V_56 = V_22 -> V_44 ;
F_2 ( V_2 , & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_56 = F_24 ( V_2 -> V_56 ) ;
V_50 . V_37 = F_33 ( V_2 -> V_37 ) ;
F_21 ( V_2 , & V_50 , 0 , sizeof( V_50 ) ) ;
if ( V_49 ) {
V_49 -> V_57 = V_22 -> V_44 ;
F_2 ( V_49 , & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_57 = F_24 ( V_49 -> V_57 ) ;
F_21 ( V_49 , & V_50 , 0 , sizeof( V_50 ) ) ;
F_23 ( V_49 ) ;
} else if ( V_2 -> V_44 == V_7 -> V_62 ) {
V_7 -> V_62 = V_22 -> V_44 ;
F_17 ( V_7 -> V_40 ) ;
}
F_13 ( V_2 ) ;
F_13 ( V_22 ) ;
F_23 ( V_2 ) ;
return V_22 ;
}
static int F_22 ( struct V_17 * V_18 )
{
struct V_21 * V_7 ;
struct V_1 * V_2 , * V_22 , * V_43 ;
int V_63 , V_64 ;
int V_3 , V_45 , V_29 ;
int V_65 , V_26 ;
V_7 = V_18 -> V_7 ;
V_2 = V_18 -> V_31 ;
V_22 = NULL ;
if ( ! V_2 -> V_43 )
return 0 ;
V_36:
V_43 = F_10 ( V_7 , V_2 -> V_43 ) ;
if ( F_11 ( V_43 ) )
return F_12 ( V_43 ) ;
F_26 ( V_43 , V_18 ) ;
F_13 ( V_43 ) ;
V_3 = V_18 -> V_34 ;
if ( V_7 -> V_12 & V_13 )
V_63 = ( F_7 ( V_2 , 14 ) | 1 ) + 1 ;
else
V_18 -> V_46 = V_63 = V_7 -> V_15 + 1 ;
F_14 ( V_38 , L_6 , V_3 , V_18 -> V_46 , V_63 ) ;
V_45 = V_7 -> V_8 - ( V_3 + 2 ) * 2 ;
V_29 = V_7 -> V_8 - ( V_43 -> V_37 + 1 ) * 2 ;
V_64 = V_63 - V_18 -> V_46 ;
if ( ! V_64 )
goto V_42;
if ( V_64 > 0 ) {
V_26 = F_5 ( V_43 , V_29 ) ;
if ( V_29 - V_26 < V_64 ) {
F_6 ( V_66 L_7 ) ;
V_18 -> V_31 = V_43 ;
V_22 = F_16 ( V_18 ) ;
if ( F_11 ( V_22 ) )
return F_12 ( V_22 ) ;
V_43 = V_18 -> V_31 ;
V_3 = V_18 -> V_34 ;
V_45 = V_7 -> V_8 - ( V_3 + 2 ) * 2 ;
V_29 = V_7 -> V_8 - ( V_43 -> V_37 + 1 ) * 2 ;
}
}
V_26 = V_65 = F_5 ( V_43 , V_45 ) ;
F_18 ( V_43 , V_45 , V_65 + V_64 ) ;
V_65 -= 4 ;
while ( V_45 > V_29 ) {
V_45 -= 2 ;
V_26 = F_5 ( V_43 , V_45 ) ;
F_18 ( V_43 , V_45 , V_26 + V_64 ) ;
}
F_20 ( V_43 , V_65 + V_64 , V_65 ,
V_26 - V_65 ) ;
V_42:
F_32 ( V_43 , V_18 -> V_48 , V_2 , 14 , V_63 ) ;
if ( ! ( V_7 -> V_12 & V_13 ) )
F_34 ( V_43 , V_18 -> V_48 , V_63 - 1 ) ;
F_13 ( V_43 ) ;
F_23 ( V_2 ) ;
V_2 = V_43 ;
if ( V_22 ) {
T_3 V_30 ;
V_18 -> V_31 = F_10 ( V_7 , V_22 -> V_43 ) ;
F_25 ( V_22 , V_18 -> V_35 , 14 ) ;
V_30 = F_24 ( V_22 -> V_44 ) ;
F_26 ( V_18 -> V_31 , V_18 ) ;
F_8 ( V_18 , & V_30 , sizeof( V_30 ) ) ;
F_23 ( V_18 -> V_31 ) ;
F_23 ( V_22 ) ;
if ( ! V_3 ) {
if ( V_22 == V_2 )
goto V_67;
F_25 ( V_2 , V_18 -> V_35 , 14 ) ;
}
}
if ( ! V_3 && V_2 -> V_43 )
goto V_36;
V_67:
V_18 -> V_31 = V_2 ;
return 0 ;
}
static int F_9 ( struct V_21 * V_7 )
{
struct V_1 * V_2 , * V_22 ;
struct V_41 V_50 ;
int V_68 , V_3 ;
T_3 V_30 ;
V_2 = NULL ;
if ( V_7 -> V_32 ) {
V_2 = F_10 ( V_7 , V_7 -> V_32 ) ;
if ( F_11 ( V_2 ) )
return F_12 ( V_2 ) ;
}
V_22 = F_29 ( V_7 ) ;
if ( F_11 ( V_22 ) ) {
F_23 ( V_2 ) ;
return F_12 ( V_22 ) ;
}
V_7 -> V_32 = V_22 -> V_44 ;
if ( ! V_7 -> V_69 ) {
V_7 -> V_33 = V_7 -> V_62 = V_22 -> V_44 ;
V_22 -> type = V_11 ;
V_22 -> V_37 = 0 ;
} else {
V_22 -> type = V_10 ;
V_22 -> V_37 = 1 ;
}
V_22 -> V_43 = 0 ;
V_22 -> V_56 = 0 ;
V_22 -> V_57 = 0 ;
V_22 -> V_58 = ++ V_7 -> V_69 ;
V_50 . V_56 = F_24 ( V_22 -> V_56 ) ;
V_50 . V_57 = F_24 ( V_22 -> V_57 ) ;
V_50 . type = V_22 -> type ;
V_50 . V_58 = V_22 -> V_58 ;
V_50 . V_37 = F_33 ( V_22 -> V_37 ) ;
V_50 . V_61 = 0 ;
F_21 ( V_22 , & V_50 , 0 , sizeof( V_50 ) ) ;
V_3 = V_7 -> V_8 - 2 ;
F_18 ( V_22 , V_3 , 14 ) ;
if ( V_2 ) {
V_2 -> V_43 = V_7 -> V_32 ;
if ( V_2 -> type == V_11 ||
V_7 -> V_12 & V_13 )
V_68 = F_7 ( V_2 , 14 ) + 1 ;
else
V_68 = V_7 -> V_15 + 1 ;
F_32 ( V_22 , 14 , V_2 , 14 , V_68 ) ;
if ( ! ( V_7 -> V_12 & V_13 ) ) {
V_68 = V_7 -> V_15 + 1 ;
F_34 ( V_22 , 14 , V_7 -> V_15 ) ;
}
V_68 = ( V_68 + 1 ) & - 2 ;
V_30 = F_24 ( V_2 -> V_44 ) ;
F_21 ( V_22 , & V_30 , 14 + V_68 , 4 ) ;
V_3 -= 2 ;
F_18 ( V_22 , V_3 , 14 + V_68 + 4 ) ;
F_23 ( V_2 ) ;
}
F_23 ( V_22 ) ;
F_17 ( V_7 -> V_40 ) ;
return 0 ;
}
