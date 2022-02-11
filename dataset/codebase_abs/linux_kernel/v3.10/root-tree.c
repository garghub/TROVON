void F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 ;
int V_7 ;
int V_8 = 0 ;
V_7 = F_2 ( V_2 , V_3 ) ;
F_3 ( V_2 , V_5 , F_4 ( V_2 , V_3 ) ,
F_5 ( int , V_7 , ( int ) sizeof( * V_5 ) ) ) ;
if ( V_7 < sizeof( * V_5 ) )
V_8 = 1 ;
if ( ! V_8 && F_6 ( V_5 )
!= F_7 ( V_5 ) ) {
if ( F_7 ( V_5 ) != 0 ) {
F_8 ( V_9 L_1
L_2
L_3
L_4
L_5
L_6 ) ;
}
V_8 = 1 ;
}
if ( V_8 ) {
memset ( & V_5 -> V_10 , 0 ,
sizeof( * V_5 ) - F_9 ( struct V_4 ,
V_10 ) ) ;
F_10 ( & V_6 ) ;
memcpy ( V_5 -> V_6 , V_6 . V_11 , V_12 ) ;
}
}
int F_11 ( struct V_13 * V_14 , T_2 V_15 ,
struct V_4 * V_5 , struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_16 V_20 ;
struct V_16 V_21 ;
struct V_1 * V_22 ;
int V_23 ;
int V_3 ;
V_20 . V_15 = V_15 ;
V_20 . type = V_24 ;
V_20 . V_25 = ( T_2 ) - 1 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_23 = F_13 ( NULL , V_14 , & V_20 , V_19 , 0 , 0 ) ;
if ( V_23 < 0 )
goto V_27;
F_14 ( V_23 == 0 ) ;
if ( V_19 -> V_28 [ 0 ] == 0 ) {
V_23 = 1 ;
goto V_27;
}
V_22 = V_19 -> V_29 [ 0 ] ;
V_3 = V_19 -> V_28 [ 0 ] - 1 ;
F_15 ( V_22 , & V_21 , V_3 ) ;
if ( V_21 . V_15 != V_15 ||
V_21 . type != V_24 ) {
V_23 = 1 ;
goto V_27;
}
if ( V_5 )
F_1 ( V_22 , V_3 , V_5 ) ;
if ( V_17 )
memcpy ( V_17 , & V_21 , sizeof( V_21 ) ) ;
V_23 = 0 ;
V_27:
F_16 ( V_19 ) ;
return V_23 ;
}
void F_17 ( struct V_4 * V_5 ,
struct V_1 * V_30 )
{
F_18 ( V_5 , V_30 -> V_31 ) ;
F_19 ( V_5 , F_20 ( V_30 ) ) ;
F_21 ( V_5 , F_22 ( V_30 ) ) ;
}
int F_23 ( struct V_32 * V_33 , struct V_13
* V_14 , struct V_16 * V_17 , struct V_4
* V_5 )
{
struct V_18 * V_19 ;
struct V_1 * V_22 ;
int V_23 ;
int V_3 ;
unsigned long V_34 ;
int V_35 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_23 = F_13 ( V_33 , V_14 , V_17 , V_19 , 0 , 1 ) ;
if ( V_23 < 0 ) {
F_24 ( V_33 , V_14 , V_23 ) ;
goto V_27;
}
if ( V_23 != 0 ) {
F_25 ( V_14 , V_19 -> V_29 [ 0 ] ) ;
F_8 ( V_36 L_7 ,
( unsigned long long ) V_17 -> V_15 , V_17 -> type ,
( unsigned long long ) V_17 -> V_25 ) ;
F_14 ( 1 ) ;
}
V_22 = V_19 -> V_29 [ 0 ] ;
V_3 = V_19 -> V_28 [ 0 ] ;
V_34 = F_4 ( V_22 , V_3 ) ;
V_35 = F_2 ( V_22 , V_3 ) ;
if ( V_35 < sizeof( * V_5 ) ) {
F_26 ( V_19 ) ;
V_23 = F_13 ( V_33 , V_14 , V_17 , V_19 ,
- 1 , 1 ) ;
if ( V_23 < 0 ) {
F_24 ( V_33 , V_14 , V_23 ) ;
goto V_27;
}
V_23 = F_27 ( V_33 , V_14 , V_19 ) ;
if ( V_23 < 0 ) {
F_24 ( V_33 , V_14 , V_23 ) ;
goto V_27;
}
F_26 ( V_19 ) ;
V_23 = F_28 ( V_33 , V_14 , V_19 ,
V_17 , sizeof( * V_5 ) ) ;
if ( V_23 < 0 ) {
F_24 ( V_33 , V_14 , V_23 ) ;
goto V_27;
}
V_22 = V_19 -> V_29 [ 0 ] ;
V_3 = V_19 -> V_28 [ 0 ] ;
V_34 = F_4 ( V_22 , V_3 ) ;
}
F_29 ( V_5 , F_6 ( V_5 ) ) ;
F_30 ( V_22 , V_5 , V_34 , sizeof( * V_5 ) ) ;
F_31 ( V_19 -> V_29 [ 0 ] ) ;
V_27:
F_16 ( V_19 ) ;
return V_23 ;
}
int F_32 ( struct V_32 * V_33 , struct V_13 * V_14 ,
struct V_16 * V_17 , struct V_4 * V_5 )
{
F_29 ( V_5 , F_6 ( V_5 ) ) ;
return F_33 ( V_33 , V_14 , V_17 , V_5 , sizeof( * V_5 ) ) ;
}
int F_34 ( struct V_13 * V_14 , T_2 V_15 )
{
struct V_13 * V_37 ;
struct V_4 * V_38 ;
struct V_16 V_17 ;
struct V_16 V_21 ;
struct V_18 * V_19 ;
int V_23 ;
T_3 V_39 ;
struct V_1 * V_40 ;
int V_3 ;
V_17 . V_15 = V_15 ;
F_35 ( & V_17 , V_24 ) ;
V_17 . V_25 = 0 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_41:
V_23 = F_13 ( NULL , V_14 , & V_17 , V_19 , 0 , 0 ) ;
if ( V_23 < 0 )
goto V_42;
while ( 1 ) {
V_40 = V_19 -> V_29 [ 0 ] ;
V_39 = F_36 ( V_40 ) ;
V_3 = V_19 -> V_28 [ 0 ] ;
if ( V_3 >= V_39 ) {
V_23 = F_37 ( V_14 , V_19 ) ;
if ( V_23 )
break;
V_40 = V_19 -> V_29 [ 0 ] ;
V_39 = F_36 ( V_40 ) ;
V_3 = V_19 -> V_28 [ 0 ] ;
}
F_15 ( V_40 , & V_17 , V_3 ) ;
if ( F_38 ( & V_17 ) != V_24 )
goto V_43;
if ( V_17 . V_15 < V_15 )
goto V_43;
if ( V_17 . V_15 > V_15 )
break;
V_38 = F_39 ( V_40 , V_3 , struct V_4 ) ;
if ( F_40 ( V_40 , V_38 ) != 0 )
goto V_43;
memcpy ( & V_21 , & V_17 , sizeof( V_17 ) ) ;
V_17 . V_25 ++ ;
F_26 ( V_19 ) ;
V_37 =
F_41 ( V_14 -> V_44 -> V_45 ,
& V_21 ) ;
if ( F_42 ( V_37 ) ) {
V_23 = F_43 ( V_37 ) ;
goto V_42;
}
V_23 = F_44 ( V_37 ) ;
if ( V_23 )
goto V_42;
goto V_41;
V_43:
V_3 ++ ;
V_19 -> V_28 [ 0 ] ++ ;
}
V_23 = 0 ;
V_42:
F_16 ( V_19 ) ;
return V_23 ;
}
int F_45 ( struct V_13 * V_45 )
{
struct V_1 * V_40 ;
struct V_18 * V_19 ;
struct V_16 V_17 ;
struct V_16 V_46 ;
struct V_13 * V_14 ;
int V_42 = 0 ;
int V_23 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_17 . V_15 = V_47 ;
V_17 . type = V_48 ;
V_17 . V_25 = 0 ;
V_46 . type = V_24 ;
V_46 . V_25 = ( T_2 ) - 1 ;
while ( 1 ) {
V_23 = F_13 ( NULL , V_45 , & V_17 , V_19 , 0 , 0 ) ;
if ( V_23 < 0 ) {
V_42 = V_23 ;
break;
}
V_40 = V_19 -> V_29 [ 0 ] ;
if ( V_19 -> V_28 [ 0 ] >= F_36 ( V_40 ) ) {
V_23 = F_37 ( V_45 , V_19 ) ;
if ( V_23 < 0 )
V_42 = V_23 ;
if ( V_23 != 0 )
break;
V_40 = V_19 -> V_29 [ 0 ] ;
}
F_15 ( V_40 , & V_17 , V_19 -> V_28 [ 0 ] ) ;
F_26 ( V_19 ) ;
if ( V_17 . V_15 != V_47 ||
V_17 . type != V_48 )
break;
V_46 . V_15 = V_17 . V_25 ;
V_17 . V_25 ++ ;
V_14 = F_46 ( V_45 -> V_44 ,
& V_46 ) ;
if ( ! F_42 ( V_14 ) )
continue;
V_23 = F_43 ( V_14 ) ;
if ( V_23 != - V_49 ) {
V_42 = V_23 ;
break;
}
V_23 = F_34 ( V_45 , V_46 . V_15 ) ;
if ( V_23 ) {
V_42 = V_23 ;
break;
}
}
F_16 ( V_19 ) ;
return V_42 ;
}
int F_47 ( struct V_32 * V_33 , struct V_13 * V_14 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 ;
int V_23 ;
struct V_4 * V_38 ;
struct V_1 * V_40 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_23 = F_13 ( V_33 , V_14 , V_17 , V_19 , - 1 , 1 ) ;
if ( V_23 < 0 )
goto V_27;
F_14 ( V_23 != 0 ) ;
V_40 = V_19 -> V_29 [ 0 ] ;
V_38 = F_39 ( V_40 , V_19 -> V_28 [ 0 ] , struct V_4 ) ;
V_23 = F_27 ( V_33 , V_14 , V_19 ) ;
V_27:
F_16 ( V_19 ) ;
return V_23 ;
}
int F_48 ( struct V_32 * V_33 ,
struct V_13 * V_45 ,
T_2 V_50 , T_2 V_51 , T_2 V_52 , T_2 * V_53 ,
const char * V_54 , int V_55 )
{
struct V_18 * V_19 ;
struct V_56 * V_57 ;
struct V_1 * V_40 ;
struct V_16 V_17 ;
unsigned long V_34 ;
int V_42 = 0 ;
int V_23 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_17 . V_15 = V_50 ;
V_17 . type = V_58 ;
V_17 . V_25 = V_51 ;
V_41:
V_23 = F_13 ( V_33 , V_45 , & V_17 , V_19 , - 1 , 1 ) ;
F_14 ( V_23 < 0 ) ;
if ( V_23 == 0 ) {
V_40 = V_19 -> V_29 [ 0 ] ;
V_57 = F_39 ( V_40 , V_19 -> V_28 [ 0 ] ,
struct V_56 ) ;
F_49 ( F_50 ( V_40 , V_57 ) != V_52 ) ;
F_49 ( F_51 ( V_40 , V_57 ) != V_55 ) ;
V_34 = ( unsigned long ) ( V_57 + 1 ) ;
F_49 ( F_52 ( V_40 , V_54 , V_34 , V_55 ) ) ;
* V_53 = F_53 ( V_40 , V_57 ) ;
V_23 = F_27 ( V_33 , V_45 , V_19 ) ;
if ( V_23 ) {
V_42 = V_23 ;
goto V_27;
}
} else
V_42 = - V_49 ;
if ( V_17 . type == V_58 ) {
F_26 ( V_19 ) ;
V_17 . V_15 = V_51 ;
V_17 . type = V_59 ;
V_17 . V_25 = V_50 ;
goto V_41;
}
V_27:
F_16 ( V_19 ) ;
return V_42 ;
}
int F_54 ( struct V_13 * V_45 ,
struct V_18 * V_19 ,
T_2 V_50 , T_2 V_51 )
{
struct V_16 V_17 ;
int V_23 ;
V_17 . V_15 = V_50 ;
V_17 . type = V_59 ;
V_17 . V_25 = V_51 ;
V_23 = F_13 ( NULL , V_45 , & V_17 , V_19 , 0 , 0 ) ;
return V_23 ;
}
int F_55 ( struct V_32 * V_33 ,
struct V_13 * V_45 ,
T_2 V_50 , T_2 V_51 , T_2 V_52 , T_2 V_53 ,
const char * V_54 , int V_55 )
{
struct V_16 V_17 ;
int V_23 ;
struct V_18 * V_19 ;
struct V_56 * V_57 ;
struct V_1 * V_40 ;
unsigned long V_34 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_17 . V_15 = V_50 ;
V_17 . type = V_58 ;
V_17 . V_25 = V_51 ;
V_41:
V_23 = F_28 ( V_33 , V_45 , V_19 , & V_17 ,
sizeof( * V_57 ) + V_55 ) ;
if ( V_23 ) {
F_24 ( V_33 , V_45 , V_23 ) ;
F_16 ( V_19 ) ;
return V_23 ;
}
V_40 = V_19 -> V_29 [ 0 ] ;
V_57 = F_39 ( V_40 , V_19 -> V_28 [ 0 ] , struct V_56 ) ;
F_56 ( V_40 , V_57 , V_52 ) ;
F_57 ( V_40 , V_57 , V_53 ) ;
F_58 ( V_40 , V_57 , V_55 ) ;
V_34 = ( unsigned long ) ( V_57 + 1 ) ;
F_30 ( V_40 , V_54 , V_34 , V_55 ) ;
F_31 ( V_40 ) ;
if ( V_17 . type == V_58 ) {
F_26 ( V_19 ) ;
V_17 . V_15 = V_51 ;
V_17 . type = V_59 ;
V_17 . V_25 = V_50 ;
goto V_41;
}
F_16 ( V_19 ) ;
return 0 ;
}
void F_59 ( struct V_4 * V_60 )
{
T_2 V_61 = F_60 ( V_60 -> V_62 . V_63 ) ;
if ( ! ( V_61 & V_64 ) ) {
V_61 |= V_64 ;
V_60 -> V_62 . V_63 = F_61 ( V_61 ) ;
V_60 -> V_63 = 0 ;
V_60 -> V_65 = 0 ;
}
}
void F_62 ( struct V_32 * V_33 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = & V_14 -> V_60 ;
struct V_66 V_67 = V_68 ;
F_63 ( & V_14 -> V_69 ) ;
V_5 -> V_70 = F_61 ( V_33 -> V_71 ) ;
V_5 -> ctime . V_72 = F_61 ( V_67 . V_73 ) ;
V_5 -> ctime . V_74 = F_64 ( V_67 . V_75 ) ;
F_65 ( & V_14 -> V_69 ) ;
}
