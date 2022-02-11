static void F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , T_1 V_6 , T_2 V_7 ,
T_2 V_8 )
{
struct V_4 V_9 = {} ;
int V_10 = ( V_7 + V_1 -> V_11 -> V_12 - 1 ) >>
V_1 -> V_11 -> V_13 ;
int V_14 = ( V_8 + V_1 -> V_11 -> V_12 - 1 ) >>
V_1 -> V_11 -> V_13 ;
if ( V_8 ) {
if ( V_6 == ( V_15 >> 30 ) ) {
F_2 ( V_1 -> V_11 , V_1 , V_5 , 0 ,
V_10 ) ;
V_6 = ( V_16 >> 30 ) ;
} else
V_9 = * V_5 ;
V_8 = ( V_6 << 30 ) | V_8 ;
}
if ( V_7 != V_8 ) {
F_3 ( V_1 , V_3 , & V_9 , V_8 , 0 ) ;
if ( V_10 - V_14 > 0 ) {
if ( V_6 == ( V_17 >> 30 ) )
F_4 ( V_1 ) ;
if ( V_6 != ( V_16 >> 30 ) )
F_2 ( V_1 -> V_11 , V_1 , V_5 ,
V_14 ,
V_10 - V_14 ) ;
}
}
}
void F_5 ( struct V_1 * V_1 )
{
struct V_2 V_3 = {} ;
struct V_4 V_5 ;
T_2 V_7 , V_8 ;
T_3 V_18 = 0 ;
T_1 V_6 = - 1 , V_19 ;
int V_20 ;
struct V_21 * V_22 = F_6 ( V_1 ) ;
if ( V_22 -> V_23 == V_24 ||
V_1 -> V_25 == V_22 -> V_26 )
return;
if ( V_1 -> V_27 == 0 )
return;
if ( V_22 -> V_23 == V_28 )
V_20 = sizeof( struct V_29 ) ;
else if ( V_22 -> V_23 == V_30 )
V_20 = sizeof( struct V_31 ) ;
else
F_7 () ;
while ( ( V_19 = F_8 ( V_1 , & V_3 , & V_5 , & V_7 , 1 ) ) != - 1 ) {
V_6 = V_19 ;
V_18 += V_7 ;
if ( V_18 > V_1 -> V_25 ) {
if ( V_18 - V_1 -> V_25 >= V_1 -> V_11 -> V_12 )
F_9 ( V_1 -> V_11 ,
L_1 ,
( unsigned ) V_1 -> V_32 ,
( long long ) V_1 -> V_25 ,
( long long ) V_18 ,
( unsigned ) V_5 . V_33 ,
( unsigned ) V_7 ) ;
V_8 = V_7 - ( V_18 - V_1 -> V_25 ) ;
V_3 . V_34 -= V_20 ;
F_1 ( V_1 , & V_3 , & V_5 , V_6 , V_7 , V_8 ) ;
V_3 . V_34 += V_20 ;
if ( F_8 ( V_1 , & V_3 , & V_5 , & V_7 , 1 ) != - 1 )
F_10 ( V_1 -> V_11 ,
L_2 ,
( unsigned ) V_1 -> V_32 ) ;
break;
}
}
V_22 -> V_26 = V_1 -> V_25 ;
F_11 ( V_3 . V_35 ) ;
}
void F_12 ( struct V_1 * V_1 )
{
struct V_2 V_3 = { NULL , 0 , { 0 , 0 } } ;
struct V_4 V_5 ;
T_2 V_7 ;
T_3 V_18 = 0 ;
T_1 V_6 = - 1 , V_19 ;
int V_20 ;
struct V_21 * V_22 = F_6 ( V_1 ) ;
if ( V_22 -> V_23 == V_24 ||
V_1 -> V_25 == V_22 -> V_26 )
return;
if ( V_22 -> V_23 == V_28 )
V_20 = sizeof( struct V_29 ) ;
else if ( V_22 -> V_23 == V_30 )
V_20 = sizeof( struct V_31 ) ;
else
V_20 = 0 ;
V_3 . V_36 = V_22 -> V_37 ;
while ( ( V_19 = F_8 ( V_1 , & V_3 , & V_5 , & V_7 , 1 ) ) != - 1 ) {
V_6 = V_19 ;
V_18 += V_7 ;
}
if ( V_6 == ( V_15 >> 30 ) ) {
V_3 . V_34 -= V_20 ;
V_18 -= V_7 ;
F_1 ( V_1 , & V_3 , & V_5 , V_6 , V_7 , 0 ) ;
if ( ! V_3 . V_35 ) {
V_22 -> V_38 =
V_3 . V_34 -
F_13 ( V_1 ) ;
F_4 ( V_1 ) ;
} else {
struct V_39 * V_40 =
(struct V_39 * ) ( V_3 . V_35 -> V_41 ) ;
V_40 -> V_42 =
F_14 ( V_3 . V_34 -
sizeof( struct V_39 ) ) ;
if ( ! F_15 ( V_1 -> V_11 , V_43 ) ||
F_16 ( V_1 -> V_11 ) -> V_44 >= 0x0201 )
F_17 ( V_3 . V_35 -> V_41 , V_3 . V_34 ) ;
else
F_17 ( V_3 . V_35 -> V_41 ,
sizeof( struct V_39 ) ) ;
F_18 ( V_3 . V_35 , V_1 ) ;
}
}
V_22 -> V_26 = V_18 ;
F_11 ( V_3 . V_35 ) ;
}
static void F_19 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
T_4 V_45 )
{
struct V_46 * V_47 = V_1 -> V_11 ;
struct V_48 * V_49 = F_16 ( V_47 ) ;
struct V_39 * V_40 = (struct V_39 * ) ( V_3 -> V_35 -> V_41 ) ;
int V_50 = sizeof( struct V_39 ) ;
V_40 -> V_42 = F_14 ( V_45 ) ;
if ( ! F_15 ( V_47 , V_43 ) || V_49 -> V_44 >= 0x0201 )
V_50 += V_45 ;
F_17 ( V_3 -> V_35 -> V_41 , V_50 ) ;
F_18 ( V_3 -> V_35 , V_1 ) ;
}
void F_20 ( struct V_1 * V_1 )
{
struct V_2 V_3 ;
struct V_4 V_5 , V_9 = {} ;
T_2 V_7 , V_8 = 0 , V_51 = 0 , V_45 ;
T_1 V_6 ;
struct V_46 * V_47 = V_1 -> V_11 ;
T_5 V_14 = V_1 -> V_25 >> V_47 -> V_13 , V_34 ;
T_6 V_52 ;
int V_20 ;
struct V_21 * V_22 = F_6 ( V_1 ) ;
if ( V_22 -> V_23 == V_28 )
V_20 = sizeof( struct V_29 ) ;
else if ( V_22 -> V_23 == V_30 )
V_20 = sizeof( struct V_31 ) ;
else
F_7 () ;
V_6 = F_21 ( V_1 , V_14 , & V_3 , & V_5 , & V_7 , & V_34 ) ;
V_52 = ( V_34 << V_47 -> V_13 ) +
( V_1 -> V_25 & ( V_47 -> V_12 - 1 ) ) ;
if ( V_6 == - 1 ) {
F_22 ( V_52 ) ;
return;
}
V_3 . V_34 -= V_20 ;
F_1 ( V_1 , & V_3 , & V_5 , V_6 , V_7 , V_52 ) ;
V_3 . V_34 += V_20 ;
if ( V_52 )
V_45 = V_3 . V_34 ;
else
V_45 = V_3 . V_34 - V_20 ;
if ( ! V_3 . V_35 )
V_45 -= F_13 ( V_1 ) ;
else
V_45 -= sizeof( struct V_39 ) ;
while ( ( V_6 = F_23 ( V_1 , & V_3 , & V_5 ,
& V_7 , 0 ) ) != - 1 ) {
if ( V_6 == ( V_53 >> 30 ) ) {
F_3 ( V_1 , & V_3 , & V_9 , V_8 , 0 ) ;
if ( V_51 ) {
F_24 ( ! V_3 . V_35 ) ;
F_2 ( V_47 , NULL , & V_3 . V_36 ,
0 , V_51 ) ;
} else if ( ! V_3 . V_35 ) {
V_22 -> V_38 = V_45 ;
F_4 ( V_1 ) ;
} else
F_19 ( V_1 ,
& V_3 , V_45 ) ;
F_11 ( V_3 . V_35 ) ;
V_3 . V_34 = sizeof( struct V_39 ) ;
V_3 . V_36 = V_5 ;
V_3 . V_35 = F_25 ( V_47 ,
F_26 ( V_47 , & V_5 , 0 ) ) ;
if ( V_7 )
V_51 =
( V_7 + V_47 -> V_12 - 1 ) >>
V_47 -> V_13 ;
else
V_51 = 1 ;
} else {
F_1 ( V_1 , & V_3 , & V_5 , V_6 , V_7 , 0 ) ;
V_3 . V_34 += V_20 ;
}
}
if ( V_51 ) {
F_24 ( ! V_3 . V_35 ) ;
F_2 ( V_47 , NULL , & V_3 . V_36 , 0 , V_51 ) ;
} else if ( ! V_3 . V_35 ) {
V_22 -> V_38 = V_45 ;
F_4 ( V_1 ) ;
} else
F_19 ( V_1 , & V_3 , V_45 ) ;
V_22 -> V_26 = V_1 -> V_25 ;
F_11 ( V_3 . V_35 ) ;
}
