static int
F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long V_4 , T_2 V_5 ,
struct V_6 * V_7 , int V_8 )
{
T_2 V_9 ;
T_2 V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 , V_16 , V_17 , V_18 ;
switch ( V_8 ) {
case V_19 :
V_16 = 1 ;
break;
case V_20 :
V_16 = 0 ;
break;
default:
return - V_21 ;
break;
}
V_9 = ( V_2 -> V_22 . V_23 -
sizeof( struct V_11 ) ) / sizeof( V_24 ) ;
V_12 = F_2 ( V_2 -> V_22 . V_23 , V_25 ) ;
if ( ! V_12 ) {
return - V_26 ;
}
F_3 ( V_12 , V_27 ) ;
V_12 -> V_28 . V_29 = 0 ;
V_12 -> V_30 = V_2 -> V_31 ;
V_12 -> V_3 = V_3 ;
V_12 -> V_32 = 0 ;
V_17 = 0 ;
while ( V_5 ) {
V_10 = F_4 ( V_9 , V_5 ) ;
V_12 -> V_33 = F_5 ( V_10 ) ;
if ( V_10 == V_5 ) {
F_6 ( V_2 , V_7 ) ;
V_12 -> V_32 = F_5 ( V_34 ) ;
V_12 -> V_28 . V_29 = ( unsigned long ) V_7 ;
}
for ( V_18 = 0 ; V_18 < V_10 ; V_18 ++ ) {
if ( V_16 ) {
V_4 += V_35 ;
} else {
V_12 -> V_36 [ V_18 ] =
F_7 ( ( ( V_24 * ) V_4 ) [ V_17 + V_18 ] ) ;
}
}
V_15 = F_8 ( V_2 , (union V_37 * ) V_12 ) ;
if ( V_15 ) {
if ( V_10 <= V_9 ) {
F_9 ( V_2 , V_7 ) ;
}
goto V_38;
}
V_5 -= V_10 ;
V_17 += V_10 ;
}
V_15 = F_10 ( V_2 , V_7 ) ;
if ( V_15 ) {
goto V_38;
}
V_14 = (struct V_13 * ) ( unsigned long ) V_7 -> V_39 ;
if ( ! V_14 ) {
V_15 = - V_26 ;
goto V_38;
}
V_15 = F_11 ( V_14 ) ;
F_12 ( V_2 , V_14 ) ;
V_38:
F_13 ( V_12 ) ;
return V_15 ;
}
int
F_14 ( struct V_1 * V_2 , V_24 * V_40 ,
int V_41 , int V_5 , T_2 V_42 ,
T_2 V_43 , V_24 * V_4 , enum V_44 V_45 ,
struct V_46 * V_47 )
{
struct V_6 * V_7 ;
struct V_48 * V_12 ;
struct V_49 * V_14 ;
T_3 V_32 ;
int V_18 , V_9 , V_10 ;
int V_15 ;
if ( ! V_4 || ! V_42 || ! V_40 || ! V_5 )
return - V_50 ;
if ( V_5 > V_51 ) {
return - V_50 ;
}
V_7 = F_15 ( V_2 ) ;
if ( ! V_7 )
return - V_26 ;
V_12 = F_2 ( V_2 -> V_22 . V_23 , V_25 ) ;
if ( ! V_12 ) {
V_15 = - V_26 ;
goto V_38;
}
F_3 ( V_12 , V_52 ) ;
V_12 -> V_28 . V_29 = ( unsigned long ) V_7 ;
V_12 -> V_30 = V_2 -> V_31 ;
V_32 = ( V_45 | V_53 | V_54 ) ;
V_9 = ( V_2 -> V_22 . V_23 -
sizeof( struct V_48 ) ) / sizeof( V_24 ) ;
if ( V_5 <= V_9 ) {
V_32 |= V_34 ;
}
V_12 -> V_32 = F_16 ( V_32 ) ;
V_12 -> V_55 = 0 ;
V_12 -> V_4 = F_7 ( * V_4 ) ;
V_12 -> V_56 = V_47 -> V_57 -> V_56 ;
V_12 -> V_58 = F_5 ( V_41 ) ;
V_12 -> V_42 = F_5 ( V_42 ) ;
V_12 -> V_5 = F_5 ( V_5 ) ;
V_12 -> V_59 = F_5 ( V_43 ) ;
V_10 = F_4 ( V_5 , V_9 ) ;
V_12 -> V_33 = F_5 ( V_10 ) ;
for ( V_18 = 0 ; V_18 < V_10 ; V_18 ++ ) {
V_12 -> V_36 [ V_18 ] = F_7 ( V_40 [ V_18 ] ) ;
}
F_6 ( V_2 , V_7 ) ;
V_15 = F_8 ( V_2 , (union V_37 * ) V_12 ) ;
if ( V_15 ) {
F_9 ( V_2 , V_7 ) ;
goto V_60;
}
V_15 = F_10 ( V_2 , V_7 ) ;
if ( V_15 ) {
goto V_60;
}
V_14 =
(struct V_49 * ) ( unsigned long ) ( V_7 -> V_39 ) ;
if ( ! V_14 ) {
V_15 = - V_26 ;
goto V_60;
}
if ( ( V_15 = F_11 ( V_14 ) ) ) {
goto V_61;
}
V_47 -> V_62 . V_63 = V_47 -> V_62 . V_64 = F_17 ( V_14 -> V_3 ) ;
F_12 ( V_2 , V_14 ) ;
V_5 -= V_10 ;
if ( V_5 ) {
V_7 -> V_39 = ( unsigned long ) NULL ;
F_18 ( & V_7 -> V_65 , 0 ) ;
V_15 = F_1 ( V_2 ,
F_5 ( V_47 -> V_62 . V_63 ) ,
( unsigned long ) & V_40 [ V_18 ] ,
V_5 , V_7 , V_20 ) ;
if ( V_15 ) {
goto V_60;
}
}
F_19 ( V_2 , V_7 ) ;
F_13 ( V_12 ) ;
return V_15 ;
V_61:
F_12 ( V_2 , V_14 ) ;
V_60:
F_13 ( V_12 ) ;
V_38:
F_19 ( V_2 , V_7 ) ;
return V_15 ;
}
int F_20 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_6 * V_7 ;
struct V_66 V_12 ;
struct V_67 * V_14 ;
int V_15 ;
V_7 = F_15 ( V_2 ) ;
if ( ! V_7 ) {
return - V_26 ;
}
F_3 ( & V_12 , V_68 ) ;
V_12 . V_28 . V_29 = ( V_24 ) ( unsigned long ) V_7 ;
V_12 . V_30 = V_2 -> V_31 ;
V_12 . V_3 = F_5 ( V_3 ) ;
F_6 ( V_2 , V_7 ) ;
V_15 = F_8 ( V_2 , (union V_37 * ) & V_12 ) ;
if ( V_15 ) {
F_9 ( V_2 , V_7 ) ;
goto V_38;
}
V_15 = F_10 ( V_2 , V_7 ) ;
if ( V_15 ) {
goto V_38;
}
V_14 = (struct V_67 * ) ( unsigned long ) V_7 -> V_39 ;
if ( ! V_14 ) {
V_15 = - V_26 ;
goto V_38;
}
V_15 = F_11 ( V_14 ) ;
F_12 ( V_2 , V_14 ) ;
V_38:
F_19 ( V_2 , V_7 ) ;
return V_15 ;
}
