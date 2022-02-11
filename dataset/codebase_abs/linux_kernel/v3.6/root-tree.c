void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 ,
struct V_6 * V_7 )
{
T_1 V_8 ;
int V_9 ;
int V_10 = 0 ;
V_9 = F_2 ( V_4 , V_5 ) ;
F_3 ( V_4 , V_7 , F_4 ( V_4 , V_5 ) ,
F_5 ( int , V_9 , ( int ) sizeof( * V_7 ) ) ) ;
if ( V_9 < sizeof( * V_7 ) )
V_10 = 1 ;
if ( ! V_10 && F_6 ( V_7 )
!= F_7 ( V_7 ) ) {
if ( F_7 ( V_7 ) != 0 ) {
F_8 ( V_11 L_1
L_2
L_3
L_4
L_5
L_6 ) ;
}
V_10 = 1 ;
}
if ( V_10 ) {
memset ( & V_7 -> V_12 , 0 ,
sizeof( * V_7 ) - F_9 ( struct V_6 ,
V_12 ) ) ;
F_10 ( & V_8 ) ;
memcpy ( V_7 -> V_8 , V_8 . V_13 , V_14 ) ;
}
}
int F_11 ( struct V_1 * V_2 , T_2 V_15 ,
struct V_6 * V_7 , struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_16 V_20 ;
struct V_16 V_21 ;
struct V_3 * V_22 ;
int V_23 ;
int V_5 ;
V_20 . V_15 = V_15 ;
V_20 . type = V_24 ;
V_20 . V_25 = ( T_2 ) - 1 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_23 = F_13 ( NULL , V_2 , & V_20 , V_19 , 0 , 0 ) ;
if ( V_23 < 0 )
goto V_27;
F_14 ( V_23 == 0 ) ;
if ( V_19 -> V_28 [ 0 ] == 0 ) {
V_23 = 1 ;
goto V_27;
}
V_22 = V_19 -> V_29 [ 0 ] ;
V_5 = V_19 -> V_28 [ 0 ] - 1 ;
F_15 ( V_22 , & V_21 , V_5 ) ;
if ( V_21 . V_15 != V_15 ||
V_21 . type != V_24 ) {
V_23 = 1 ;
goto V_27;
}
if ( V_7 )
F_1 ( V_2 , V_22 , V_5 , V_7 ) ;
if ( V_17 )
memcpy ( V_17 , & V_21 , sizeof( V_21 ) ) ;
V_23 = 0 ;
V_27:
F_16 ( V_19 ) ;
return V_23 ;
}
void F_17 ( struct V_6 * V_7 ,
struct V_3 * V_30 )
{
F_18 ( V_7 , V_30 -> V_31 ) ;
F_19 ( V_7 , F_20 ( V_30 ) ) ;
F_21 ( V_7 , F_22 ( V_30 ) ) ;
}
int F_23 ( struct V_32 * V_33 , struct V_1
* V_2 , struct V_16 * V_17 , struct V_6
* V_7 )
{
struct V_18 * V_19 ;
struct V_3 * V_22 ;
int V_23 ;
int V_5 ;
unsigned long V_34 ;
int V_35 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_23 = F_13 ( V_33 , V_2 , V_17 , V_19 , 0 , 1 ) ;
if ( V_23 < 0 )
goto V_36;
if ( V_23 != 0 ) {
F_24 ( V_2 , V_19 -> V_29 [ 0 ] ) ;
F_8 ( V_37 L_7 ,
( unsigned long long ) V_17 -> V_15 , V_17 -> type ,
( unsigned long long ) V_17 -> V_25 ) ;
F_14 ( 1 ) ;
}
V_22 = V_19 -> V_29 [ 0 ] ;
V_5 = V_19 -> V_28 [ 0 ] ;
V_34 = F_4 ( V_22 , V_5 ) ;
V_35 = F_2 ( V_22 , V_5 ) ;
if ( V_35 < sizeof( * V_7 ) ) {
F_25 ( V_19 ) ;
V_23 = F_13 ( V_33 , V_2 , V_17 , V_19 ,
- 1 , 1 ) ;
if ( V_23 < 0 )
goto V_36;
V_23 = F_26 ( V_33 , V_2 , V_19 ) ;
if ( V_23 < 0 )
goto V_36;
F_25 ( V_19 ) ;
V_23 = F_27 ( V_33 , V_2 , V_19 ,
V_17 , sizeof( * V_7 ) ) ;
if ( V_23 < 0 )
goto V_36;
V_22 = V_19 -> V_29 [ 0 ] ;
V_5 = V_19 -> V_28 [ 0 ] ;
V_34 = F_4 ( V_22 , V_5 ) ;
}
F_28 ( V_7 , F_6 ( V_7 ) ) ;
F_29 ( V_22 , V_7 , V_34 , sizeof( * V_7 ) ) ;
F_30 ( V_19 -> V_29 [ 0 ] ) ;
V_27:
F_16 ( V_19 ) ;
return V_23 ;
V_36:
F_31 ( V_33 , V_2 , V_23 ) ;
goto V_27;
}
int F_32 ( struct V_32 * V_33 , struct V_1 * V_2 ,
struct V_16 * V_17 , struct V_6 * V_7 )
{
F_28 ( V_7 , F_6 ( V_7 ) ) ;
return F_33 ( V_33 , V_2 , V_17 , V_7 , sizeof( * V_7 ) ) ;
}
int F_34 ( struct V_1 * V_2 , T_2 V_15 )
{
struct V_1 * V_38 ;
struct V_6 * V_39 ;
struct V_16 V_17 ;
struct V_16 V_21 ;
struct V_18 * V_19 ;
int V_23 ;
T_3 V_40 ;
struct V_3 * V_41 ;
int V_5 ;
V_17 . V_15 = V_15 ;
F_35 ( & V_17 , V_24 ) ;
V_17 . V_25 = 0 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_42:
V_23 = F_13 ( NULL , V_2 , & V_17 , V_19 , 0 , 0 ) ;
if ( V_23 < 0 )
goto V_43;
while ( 1 ) {
V_41 = V_19 -> V_29 [ 0 ] ;
V_40 = F_36 ( V_41 ) ;
V_5 = V_19 -> V_28 [ 0 ] ;
if ( V_5 >= V_40 ) {
V_23 = F_37 ( V_2 , V_19 ) ;
if ( V_23 )
break;
V_41 = V_19 -> V_29 [ 0 ] ;
V_40 = F_36 ( V_41 ) ;
V_5 = V_19 -> V_28 [ 0 ] ;
}
F_15 ( V_41 , & V_17 , V_5 ) ;
if ( F_38 ( & V_17 ) != V_24 )
goto V_44;
if ( V_17 . V_15 < V_15 )
goto V_44;
if ( V_17 . V_15 > V_15 )
break;
V_39 = F_39 ( V_41 , V_5 , struct V_6 ) ;
if ( F_40 ( V_41 , V_39 ) != 0 )
goto V_44;
memcpy ( & V_21 , & V_17 , sizeof( V_17 ) ) ;
V_17 . V_25 ++ ;
F_25 ( V_19 ) ;
V_38 =
F_41 ( V_2 -> V_45 -> V_46 ,
& V_21 ) ;
if ( F_42 ( V_38 ) ) {
V_23 = F_43 ( V_38 ) ;
goto V_43;
}
V_23 = F_44 ( V_38 ) ;
if ( V_23 )
goto V_43;
goto V_42;
V_44:
V_5 ++ ;
V_19 -> V_28 [ 0 ] ++ ;
}
V_23 = 0 ;
V_43:
F_16 ( V_19 ) ;
return V_23 ;
}
int F_45 ( struct V_1 * V_46 )
{
struct V_3 * V_41 ;
struct V_18 * V_19 ;
struct V_16 V_17 ;
struct V_16 V_47 ;
struct V_1 * V_2 ;
int V_43 = 0 ;
int V_23 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_17 . V_15 = V_48 ;
V_17 . type = V_49 ;
V_17 . V_25 = 0 ;
V_47 . type = V_24 ;
V_47 . V_25 = ( T_2 ) - 1 ;
while ( 1 ) {
V_23 = F_13 ( NULL , V_46 , & V_17 , V_19 , 0 , 0 ) ;
if ( V_23 < 0 ) {
V_43 = V_23 ;
break;
}
V_41 = V_19 -> V_29 [ 0 ] ;
if ( V_19 -> V_28 [ 0 ] >= F_36 ( V_41 ) ) {
V_23 = F_37 ( V_46 , V_19 ) ;
if ( V_23 < 0 )
V_43 = V_23 ;
if ( V_23 != 0 )
break;
V_41 = V_19 -> V_29 [ 0 ] ;
}
F_15 ( V_41 , & V_17 , V_19 -> V_28 [ 0 ] ) ;
F_25 ( V_19 ) ;
if ( V_17 . V_15 != V_48 ||
V_17 . type != V_49 )
break;
V_47 . V_15 = V_17 . V_25 ;
V_17 . V_25 ++ ;
V_2 = F_46 ( V_46 -> V_45 ,
& V_47 ) ;
if ( ! F_42 ( V_2 ) )
continue;
V_23 = F_43 ( V_2 ) ;
if ( V_23 != - V_50 ) {
V_43 = V_23 ;
break;
}
V_23 = F_34 ( V_46 , V_47 . V_15 ) ;
if ( V_23 ) {
V_43 = V_23 ;
break;
}
}
F_16 ( V_19 ) ;
return V_43 ;
}
int F_47 ( struct V_32 * V_33 , struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 ;
int V_23 ;
struct V_6 * V_39 ;
struct V_3 * V_41 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_23 = F_13 ( V_33 , V_2 , V_17 , V_19 , - 1 , 1 ) ;
if ( V_23 < 0 )
goto V_27;
F_14 ( V_23 != 0 ) ;
V_41 = V_19 -> V_29 [ 0 ] ;
V_39 = F_39 ( V_41 , V_19 -> V_28 [ 0 ] , struct V_6 ) ;
V_23 = F_26 ( V_33 , V_2 , V_19 ) ;
V_27:
F_16 ( V_19 ) ;
return V_23 ;
}
int F_48 ( struct V_32 * V_33 ,
struct V_1 * V_46 ,
T_2 V_51 , T_2 V_52 , T_2 V_53 , T_2 * V_54 ,
const char * V_55 , int V_56 )
{
struct V_18 * V_19 ;
struct V_57 * V_58 ;
struct V_3 * V_41 ;
struct V_16 V_17 ;
unsigned long V_34 ;
int V_43 = 0 ;
int V_23 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_17 . V_15 = V_51 ;
V_17 . type = V_59 ;
V_17 . V_25 = V_52 ;
V_42:
V_23 = F_13 ( V_33 , V_46 , & V_17 , V_19 , - 1 , 1 ) ;
F_14 ( V_23 < 0 ) ;
if ( V_23 == 0 ) {
V_41 = V_19 -> V_29 [ 0 ] ;
V_58 = F_39 ( V_41 , V_19 -> V_28 [ 0 ] ,
struct V_57 ) ;
F_49 ( F_50 ( V_41 , V_58 ) != V_53 ) ;
F_49 ( F_51 ( V_41 , V_58 ) != V_56 ) ;
V_34 = ( unsigned long ) ( V_58 + 1 ) ;
F_49 ( F_52 ( V_41 , V_55 , V_34 , V_56 ) ) ;
* V_54 = F_53 ( V_41 , V_58 ) ;
V_23 = F_26 ( V_33 , V_46 , V_19 ) ;
if ( V_23 ) {
V_43 = V_23 ;
goto V_27;
}
} else
V_43 = - V_50 ;
if ( V_17 . type == V_59 ) {
F_25 ( V_19 ) ;
V_17 . V_15 = V_52 ;
V_17 . type = V_60 ;
V_17 . V_25 = V_51 ;
goto V_42;
}
V_27:
F_16 ( V_19 ) ;
return V_43 ;
}
int F_54 ( struct V_1 * V_46 ,
struct V_18 * V_19 ,
T_2 V_51 , T_2 V_52 )
{
struct V_16 V_17 ;
int V_23 ;
V_17 . V_15 = V_51 ;
V_17 . type = V_60 ;
V_17 . V_25 = V_52 ;
V_23 = F_13 ( NULL , V_46 , & V_17 , V_19 , 0 , 0 ) ;
return V_23 ;
}
int F_55 ( struct V_32 * V_33 ,
struct V_1 * V_46 ,
T_2 V_51 , T_2 V_52 , T_2 V_53 , T_2 V_54 ,
const char * V_55 , int V_56 )
{
struct V_16 V_17 ;
int V_23 ;
struct V_18 * V_19 ;
struct V_57 * V_58 ;
struct V_3 * V_41 ;
unsigned long V_34 ;
V_19 = F_12 () ;
if ( ! V_19 )
return - V_26 ;
V_17 . V_15 = V_51 ;
V_17 . type = V_59 ;
V_17 . V_25 = V_52 ;
V_42:
V_23 = F_27 ( V_33 , V_46 , V_19 , & V_17 ,
sizeof( * V_58 ) + V_56 ) ;
if ( V_23 ) {
F_31 ( V_33 , V_46 , V_23 ) ;
F_16 ( V_19 ) ;
return V_23 ;
}
V_41 = V_19 -> V_29 [ 0 ] ;
V_58 = F_39 ( V_41 , V_19 -> V_28 [ 0 ] , struct V_57 ) ;
F_56 ( V_41 , V_58 , V_53 ) ;
F_57 ( V_41 , V_58 , V_54 ) ;
F_58 ( V_41 , V_58 , V_56 ) ;
V_34 = ( unsigned long ) ( V_58 + 1 ) ;
F_29 ( V_41 , V_55 , V_34 , V_56 ) ;
F_30 ( V_41 ) ;
if ( V_17 . type == V_59 ) {
F_25 ( V_19 ) ;
V_17 . V_15 = V_52 ;
V_17 . type = V_60 ;
V_17 . V_25 = V_51 ;
goto V_42;
}
F_16 ( V_19 ) ;
return 0 ;
}
void F_59 ( struct V_6 * V_61 )
{
T_2 V_62 = F_60 ( V_61 -> V_63 . V_64 ) ;
if ( ! ( V_62 & V_65 ) ) {
V_62 |= V_65 ;
V_61 -> V_63 . V_64 = F_61 ( V_62 ) ;
V_61 -> V_64 = 0 ;
V_61 -> V_66 = 0 ;
}
}
void F_62 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_61 ;
struct V_67 V_68 = V_69 ;
F_63 ( & V_2 -> V_70 ) ;
V_7 -> V_71 = F_61 ( V_33 -> V_72 ) ;
V_7 -> ctime . V_73 = F_61 ( V_68 . V_74 ) ;
V_7 -> ctime . V_75 = F_64 ( V_68 . V_76 ) ;
F_65 ( & V_2 -> V_70 ) ;
}
