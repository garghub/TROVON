static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
if ( V_4 -> V_6 ) {
V_5 = F_2 ( V_2 , V_4 -> V_6 ) ;
if ( V_5 && V_5 != - V_7 ) {
F_3 ( V_2 -> V_8 , L_1 ) ;
goto V_9;
}
}
if ( V_4 -> V_10 ) {
V_5 = F_4 ( V_2 , 0 , V_4 -> V_10 , 0 ) ;
if ( V_5 && V_5 != - V_7 ) {
F_3 ( V_2 -> V_8 , L_2 ) ;
goto V_9;
}
}
if ( V_4 -> V_11 ) {
V_5 = F_5 ( V_2 , 0 , 0 ,
V_4 -> V_11 ,
V_4 -> V_12 ) ;
if ( V_5 && V_5 != - V_7 ) {
F_3 ( V_2 -> V_8 , L_3 ) ;
goto V_9;
}
}
V_5 = 0 ;
V_9:
return V_5 ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 =
F_7 ( V_14 -> V_17 ) ;
struct V_1 * V_18 = V_14 -> V_19 ;
struct V_1 * V_20 = V_14 -> V_21 ;
struct V_22 * V_23 ;
int V_24 , V_5 ;
V_24 = V_14 - V_14 -> V_17 -> V_14 ;
V_23 = & V_16 -> V_23 [ V_24 ] ;
V_5 = F_1 ( V_18 , & V_23 -> V_19 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_20 , & V_23 -> V_21 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int
F_8 ( struct V_25 * V_26 ,
unsigned int V_27 ,
struct V_3 * V_2 ,
const struct V_25 * * V_28 ,
const char * * V_29 )
{
struct V_25 * V_30 ;
struct V_31 * V_31 ;
int V_5 ;
V_30 = F_9 ( V_26 , L_4 , 0 ) ;
if ( ! V_30 )
return - V_32 ;
* V_28 = V_30 ;
V_5 = F_10 ( V_26 , V_29 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_11 ( V_26 , & V_2 -> V_11 , & V_2 -> V_12 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_6 = F_12 ( V_26 , NULL ) ;
V_2 -> V_6 |= V_27 ;
if ( F_13 ( V_26 , L_5 ) ) {
V_31 = F_14 ( V_26 , 0 ) ;
if ( F_15 ( V_31 ) ) {
V_5 = F_16 ( V_31 ) ;
return V_5 ;
}
V_2 -> V_10 = F_17 ( V_31 ) ;
} else if ( F_13 ( V_26 , L_6 ) ) {
F_18 ( V_26 ,
L_6 ,
& V_2 -> V_10 ) ;
} else {
V_31 = F_14 ( V_30 , 0 ) ;
if ( ! F_15 ( V_31 ) )
V_2 -> V_10 = F_17 ( V_31 ) ;
}
return 0 ;
}
static int F_19 ( struct V_25 * V_30 ,
int V_27 ,
struct V_33 * V_34 ,
struct V_22 * V_23 )
{
struct V_25 * V_26 ;
int V_5 ;
V_5 = - V_35 ;
V_26 = F_20 ( V_30 , L_7 ) ;
if ( V_26 ) {
V_5 = F_8 ( V_26 , V_27 ,
& V_23 -> V_21 ,
& V_34 -> V_36 ,
& V_34 -> V_37 ) ;
F_21 ( V_26 ) ;
}
if ( V_5 < 0 )
return V_5 ;
V_5 = - V_35 ;
V_26 = F_20 ( V_30 , L_8 ) ;
if ( V_26 ) {
V_5 = F_8 ( V_26 , V_27 ,
& V_23 -> V_19 ,
& V_34 -> V_38 ,
& V_34 -> V_39 ) ;
F_21 ( V_26 ) ;
}
return V_5 ;
}
static int F_22 ( struct V_25 * V_30 ,
struct V_15 * V_16 ,
struct V_40 * V_8 ,
int V_41 )
{
struct V_33 * V_34 = V_16 -> V_42 . V_34 ;
struct V_22 * V_23 = V_16 -> V_23 ;
struct V_25 * V_26 ;
char * V_29 ;
unsigned int V_27 ;
int V_5 ;
F_23 ( & V_16 -> V_42 , L_9 ) ;
V_27 = F_12 ( V_30 , L_10 ) &
( V_43 | V_44 ) ;
if ( F_13 ( V_30 , L_11 ) ) {
V_5 = F_24 ( & V_16 -> V_42 ,
L_11 ) ;
if ( V_5 )
return V_5 ;
}
if ( F_13 ( V_30 , L_12 ) ) {
V_5 = F_25 ( & V_16 -> V_42 ,
L_12 ) ;
if ( V_5 )
return V_5 ;
}
V_26 = NULL ;
for (; ; ) {
if ( V_41 ) {
V_26 = F_26 ( V_30 , V_26 ) ;
if ( ! V_26 )
break;
}
V_5 = F_19 ( V_41 ? V_26 : V_30 ,
V_27 , V_34 , V_23 ) ;
if ( V_5 < 0 )
goto V_9;
V_23 -> V_21 . V_6 = V_23 -> V_19 . V_6 ;
if ( ! V_34 -> V_37 || ! V_34 -> V_39 ) {
V_5 = - V_35 ;
goto V_9;
}
V_34 -> V_45 = V_34 -> V_36 ;
V_29 = F_27 ( V_8 ,
strlen ( V_34 -> V_37 ) +
strlen ( V_34 -> V_39 ) + 2 ,
V_46 ) ;
sprintf ( V_29 , L_13 , V_34 -> V_37 ,
V_34 -> V_39 ) ;
V_34 -> V_29 = V_34 -> V_47 = V_29 ;
if ( ! V_41 )
break;
V_34 ++ ;
V_23 ++ ;
}
V_34 = V_16 -> V_42 . V_34 ;
if ( ! V_16 -> V_42 . V_29 )
V_16 -> V_42 . V_29 = V_34 -> V_29 ;
F_28 ( V_8 , L_14 , V_16 -> V_42 . V_29 ) ;
F_28 ( V_8 , L_15 , V_27 ) ;
V_23 = V_16 -> V_23 ;
F_28 ( V_8 , L_16 ,
V_34 -> V_37 ,
V_23 -> V_21 . V_6 ,
V_23 -> V_21 . V_10 ) ;
F_28 ( V_8 , L_17 ,
V_34 -> V_39 ,
V_23 -> V_19 . V_6 ,
V_23 -> V_19 . V_10 ) ;
return 0 ;
V_9:
F_21 ( V_26 ) ;
return V_5 ;
}
static int F_29 ( struct V_48 * V_49 )
{
struct V_50 * V_17 = F_30 ( V_49 ) ;
struct V_33 * V_34 ;
struct V_25 * V_26 ;
int V_51 ;
for ( V_51 = 0 , V_34 = V_17 -> V_34 ;
V_51 < V_17 -> V_51 ;
V_51 ++ , V_34 ++ ) {
V_26 = (struct V_25 * ) V_34 -> V_36 ;
if ( V_26 )
F_21 ( V_26 ) ;
V_26 = (struct V_25 * ) V_34 -> V_38 ;
if ( V_26 )
F_21 ( V_26 ) ;
}
return 0 ;
}
static int F_31 ( struct V_48 * V_49 )
{
struct V_15 * V_16 ;
struct V_33 * V_34 ;
struct V_25 * V_26 = V_49 -> V_8 . V_52 ;
struct V_40 * V_8 = & V_49 -> V_8 ;
int V_51 , V_41 , V_5 ;
if ( V_26 && F_20 ( V_26 , L_18 ) ) {
V_51 = F_32 ( V_26 ) ;
V_41 = 1 ;
} else {
V_51 = 1 ;
V_41 = 0 ;
}
V_16 = F_27 ( V_8 ,
sizeof( * V_16 ) + sizeof( * V_34 ) * V_51 ,
V_46 ) ;
if ( ! V_16 )
return - V_53 ;
V_16 -> V_42 . V_54 = V_55 ;
V_16 -> V_42 . V_8 = V_8 ;
V_34 = V_16 -> V_34 ;
V_16 -> V_42 . V_34 = V_34 ;
V_16 -> V_42 . V_51 = V_51 ;
V_16 -> V_23 = F_27 ( V_8 ,
sizeof( * V_16 -> V_23 ) * V_51 ,
V_46 ) ;
if ( ! V_16 -> V_23 )
return - V_53 ;
if ( V_26 && F_33 ( V_26 ) ) {
V_5 = F_22 ( V_26 , V_16 , V_8 , V_41 ) ;
if ( V_5 < 0 ) {
if ( V_5 != - V_56 )
F_3 ( V_8 , L_19 , V_5 ) ;
goto V_9;
}
if ( V_51 == 1 )
V_34 -> V_37 = NULL ;
} else {
struct V_57 * V_58 ;
V_58 = V_8 -> V_59 ;
if ( ! V_58 ) {
F_3 ( V_8 , L_20 ) ;
return - V_35 ;
}
if ( ! V_58 -> V_29 ||
! V_58 -> V_19 . V_29 ||
! V_58 -> V_18 ||
! V_58 -> V_60 ||
! V_58 -> V_21 . V_29 ) {
F_3 ( V_8 , L_21 ) ;
return - V_35 ;
}
V_16 -> V_42 . V_29 = ( V_58 -> V_17 ) ? V_58 -> V_17 : V_58 -> V_29 ;
V_34 -> V_29 = V_58 -> V_29 ;
V_34 -> V_47 = V_58 -> V_29 ;
V_34 -> V_61 = V_58 -> V_60 ;
V_34 -> V_62 = V_58 -> V_18 ;
V_34 -> V_37 = V_58 -> V_21 . V_29 ;
V_34 -> V_39 = V_58 -> V_19 . V_29 ;
memcpy ( & V_16 -> V_23 -> V_21 , & V_58 -> V_21 ,
sizeof( V_16 -> V_23 -> V_21 ) ) ;
memcpy ( & V_16 -> V_23 -> V_19 , & V_58 -> V_19 ,
sizeof( V_16 -> V_23 -> V_19 ) ) ;
V_16 -> V_23 -> V_21 . V_6 |= V_58 -> V_27 ;
V_16 -> V_23 -> V_19 . V_6 |= V_58 -> V_27 ;
}
V_34 -> V_63 = F_6 ;
F_34 ( & V_16 -> V_42 , V_16 ) ;
V_5 = F_35 ( & V_49 -> V_8 , & V_16 -> V_42 ) ;
V_9:
F_29 ( V_49 ) ;
return V_5 ;
}
