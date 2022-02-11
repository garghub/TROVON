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
int F_11 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_4 * V_19 ,
struct V_15 * V_20 )
{
struct V_15 V_21 ;
struct V_1 * V_22 ;
int V_23 ;
int V_3 ;
V_23 = F_12 ( NULL , V_14 , V_16 , V_18 , 0 , 0 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_16 -> V_24 != - 1ULL ) {
if ( V_23 > 0 )
goto V_25;
} else {
F_13 ( V_23 == 0 ) ;
if ( V_18 -> V_26 [ 0 ] == 0 )
goto V_25;
V_18 -> V_26 [ 0 ] -- ;
V_23 = 0 ;
}
V_22 = V_18 -> V_27 [ 0 ] ;
V_3 = V_18 -> V_26 [ 0 ] ;
F_14 ( V_22 , & V_21 , V_3 ) ;
if ( V_21 . V_28 != V_16 -> V_28 ||
V_21 . type != V_29 ) {
V_23 = 1 ;
goto V_25;
}
if ( V_19 )
F_1 ( V_22 , V_3 , V_19 ) ;
if ( V_20 )
memcpy ( V_20 , & V_21 , sizeof( V_21 ) ) ;
V_25:
F_15 ( V_18 ) ;
return V_23 ;
}
void F_16 ( struct V_4 * V_5 ,
struct V_1 * V_30 )
{
F_17 ( V_5 , V_30 -> V_31 ) ;
F_18 ( V_5 , F_19 ( V_30 ) ) ;
F_20 ( V_5 , F_21 ( V_30 ) ) ;
}
int F_22 ( struct V_32 * V_33 , struct V_13
* V_14 , struct V_15 * V_34 , struct V_4
* V_5 )
{
struct V_17 * V_18 ;
struct V_1 * V_22 ;
int V_23 ;
int V_3 ;
unsigned long V_35 ;
int V_36 ;
V_18 = F_23 () ;
if ( ! V_18 )
return - V_37 ;
V_23 = F_12 ( V_33 , V_14 , V_34 , V_18 , 0 , 1 ) ;
if ( V_23 < 0 ) {
F_24 ( V_33 , V_14 , V_23 ) ;
goto V_25;
}
if ( V_23 != 0 ) {
F_25 ( V_14 , V_18 -> V_27 [ 0 ] ) ;
F_8 ( V_38 L_7 ,
( unsigned long long ) V_34 -> V_28 , V_34 -> type ,
( unsigned long long ) V_34 -> V_24 ) ;
F_13 ( 1 ) ;
}
V_22 = V_18 -> V_27 [ 0 ] ;
V_3 = V_18 -> V_26 [ 0 ] ;
V_35 = F_4 ( V_22 , V_3 ) ;
V_36 = F_2 ( V_22 , V_3 ) ;
if ( V_36 < sizeof( * V_5 ) ) {
F_15 ( V_18 ) ;
V_23 = F_12 ( V_33 , V_14 , V_34 , V_18 ,
- 1 , 1 ) ;
if ( V_23 < 0 ) {
F_24 ( V_33 , V_14 , V_23 ) ;
goto V_25;
}
V_23 = F_26 ( V_33 , V_14 , V_18 ) ;
if ( V_23 < 0 ) {
F_24 ( V_33 , V_14 , V_23 ) ;
goto V_25;
}
F_15 ( V_18 ) ;
V_23 = F_27 ( V_33 , V_14 , V_18 ,
V_34 , sizeof( * V_5 ) ) ;
if ( V_23 < 0 ) {
F_24 ( V_33 , V_14 , V_23 ) ;
goto V_25;
}
V_22 = V_18 -> V_27 [ 0 ] ;
V_3 = V_18 -> V_26 [ 0 ] ;
V_35 = F_4 ( V_22 , V_3 ) ;
}
F_28 ( V_5 , F_6 ( V_5 ) ) ;
F_29 ( V_22 , V_5 , V_35 , sizeof( * V_5 ) ) ;
F_30 ( V_18 -> V_27 [ 0 ] ) ;
V_25:
F_31 ( V_18 ) ;
return V_23 ;
}
int F_32 ( struct V_32 * V_33 , struct V_13 * V_14 ,
struct V_15 * V_34 , struct V_4 * V_5 )
{
F_28 ( V_5 , F_6 ( V_5 ) ) ;
return F_33 ( V_33 , V_14 , V_34 , V_5 , sizeof( * V_5 ) ) ;
}
int F_34 ( struct V_13 * V_39 )
{
struct V_1 * V_40 ;
struct V_17 * V_18 ;
struct V_15 V_34 ;
struct V_15 V_20 ;
struct V_13 * V_14 ;
int V_41 = 0 ;
int V_23 ;
bool V_42 = true ;
if ( V_39 -> V_43 -> V_44 -> V_45 & V_46 )
V_42 = false ;
V_18 = F_23 () ;
if ( ! V_18 )
return - V_37 ;
V_34 . V_28 = V_47 ;
V_34 . type = V_48 ;
V_34 . V_24 = 0 ;
V_20 . type = V_29 ;
V_20 . V_24 = ( V_49 ) - 1 ;
while ( 1 ) {
V_23 = F_12 ( NULL , V_39 , & V_34 , V_18 , 0 , 0 ) ;
if ( V_23 < 0 ) {
V_41 = V_23 ;
break;
}
V_40 = V_18 -> V_27 [ 0 ] ;
if ( V_18 -> V_26 [ 0 ] >= F_35 ( V_40 ) ) {
V_23 = F_36 ( V_39 , V_18 ) ;
if ( V_23 < 0 )
V_41 = V_23 ;
if ( V_23 != 0 )
break;
V_40 = V_18 -> V_27 [ 0 ] ;
}
F_14 ( V_40 , & V_34 , V_18 -> V_26 [ 0 ] ) ;
F_15 ( V_18 ) ;
if ( V_34 . V_28 != V_47 ||
V_34 . type != V_48 )
break;
V_20 . V_28 = V_34 . V_24 ;
V_34 . V_24 ++ ;
V_14 = F_37 ( V_39 , & V_20 ) ;
V_41 = F_38 ( V_14 ) ;
if ( V_41 && V_41 != - V_50 ) {
break;
} else if ( V_41 == - V_50 ) {
struct V_32 * V_33 ;
F_15 ( V_18 ) ;
V_33 = F_39 ( V_39 ) ;
if ( F_40 ( V_33 ) ) {
V_41 = F_41 ( V_33 ) ;
F_42 ( V_39 -> V_43 , V_41 ,
L_8
L_9 ) ;
break;
}
V_41 = F_43 ( V_33 , V_39 ,
V_20 . V_28 ) ;
F_44 ( V_33 , V_39 ) ;
if ( V_41 ) {
F_42 ( V_39 -> V_43 , V_41 ,
L_10
L_11 ) ;
break;
}
continue;
}
if ( F_45 ( & V_14 -> V_19 ) == 0 ) {
F_46 ( V_14 ) ;
continue;
}
V_41 = F_47 ( V_14 ) ;
if ( V_41 ) {
F_48 ( V_14 ) ;
break;
}
V_14 -> V_51 = 1 ;
V_41 = F_49 ( V_14 -> V_43 , V_14 ) ;
if ( V_41 ) {
F_13 ( V_41 == - V_52 ) ;
F_48 ( V_14 ) ;
break;
}
}
F_31 ( V_18 ) ;
return V_41 ;
}
int F_50 ( struct V_32 * V_33 , struct V_13 * V_14 ,
struct V_15 * V_34 )
{
struct V_17 * V_18 ;
int V_23 ;
V_18 = F_23 () ;
if ( ! V_18 )
return - V_37 ;
V_23 = F_12 ( V_33 , V_14 , V_34 , V_18 , - 1 , 1 ) ;
if ( V_23 < 0 )
goto V_25;
F_13 ( V_23 != 0 ) ;
V_23 = F_26 ( V_33 , V_14 , V_18 ) ;
V_25:
F_31 ( V_18 ) ;
return V_23 ;
}
int F_51 ( struct V_32 * V_33 ,
struct V_13 * V_39 ,
V_49 V_53 , V_49 V_54 , V_49 V_55 , V_49 * V_56 ,
const char * V_57 , int V_58 )
{
struct V_17 * V_18 ;
struct V_59 * V_60 ;
struct V_1 * V_40 ;
struct V_15 V_34 ;
unsigned long V_35 ;
int V_41 = 0 ;
int V_23 ;
V_18 = F_23 () ;
if ( ! V_18 )
return - V_37 ;
V_34 . V_28 = V_53 ;
V_34 . type = V_61 ;
V_34 . V_24 = V_54 ;
V_62:
V_23 = F_12 ( V_33 , V_39 , & V_34 , V_18 , - 1 , 1 ) ;
F_13 ( V_23 < 0 ) ;
if ( V_23 == 0 ) {
V_40 = V_18 -> V_27 [ 0 ] ;
V_60 = F_52 ( V_40 , V_18 -> V_26 [ 0 ] ,
struct V_59 ) ;
F_53 ( F_54 ( V_40 , V_60 ) != V_55 ) ;
F_53 ( F_55 ( V_40 , V_60 ) != V_58 ) ;
V_35 = ( unsigned long ) ( V_60 + 1 ) ;
F_53 ( F_56 ( V_40 , V_57 , V_35 , V_58 ) ) ;
* V_56 = F_57 ( V_40 , V_60 ) ;
V_23 = F_26 ( V_33 , V_39 , V_18 ) ;
if ( V_23 ) {
V_41 = V_23 ;
goto V_25;
}
} else
V_41 = - V_50 ;
if ( V_34 . type == V_61 ) {
F_15 ( V_18 ) ;
V_34 . V_28 = V_54 ;
V_34 . type = V_63 ;
V_34 . V_24 = V_53 ;
goto V_62;
}
V_25:
F_31 ( V_18 ) ;
return V_41 ;
}
int F_58 ( struct V_13 * V_39 ,
struct V_17 * V_18 ,
V_49 V_53 , V_49 V_54 )
{
struct V_15 V_34 ;
int V_23 ;
V_34 . V_28 = V_53 ;
V_34 . type = V_63 ;
V_34 . V_24 = V_54 ;
V_23 = F_12 ( NULL , V_39 , & V_34 , V_18 , 0 , 0 ) ;
return V_23 ;
}
int F_59 ( struct V_32 * V_33 ,
struct V_13 * V_39 ,
V_49 V_53 , V_49 V_54 , V_49 V_55 , V_49 V_56 ,
const char * V_57 , int V_58 )
{
struct V_15 V_34 ;
int V_23 ;
struct V_17 * V_18 ;
struct V_59 * V_60 ;
struct V_1 * V_40 ;
unsigned long V_35 ;
V_18 = F_23 () ;
if ( ! V_18 )
return - V_37 ;
V_34 . V_28 = V_53 ;
V_34 . type = V_61 ;
V_34 . V_24 = V_54 ;
V_62:
V_23 = F_27 ( V_33 , V_39 , V_18 , & V_34 ,
sizeof( * V_60 ) + V_58 ) ;
if ( V_23 ) {
F_24 ( V_33 , V_39 , V_23 ) ;
F_31 ( V_18 ) ;
return V_23 ;
}
V_40 = V_18 -> V_27 [ 0 ] ;
V_60 = F_52 ( V_40 , V_18 -> V_26 [ 0 ] , struct V_59 ) ;
F_60 ( V_40 , V_60 , V_55 ) ;
F_61 ( V_40 , V_60 , V_56 ) ;
F_62 ( V_40 , V_60 , V_58 ) ;
V_35 = ( unsigned long ) ( V_60 + 1 ) ;
F_29 ( V_40 , V_57 , V_35 , V_58 ) ;
F_30 ( V_40 ) ;
if ( V_34 . type == V_61 ) {
F_15 ( V_18 ) ;
V_34 . V_28 = V_54 ;
V_34 . type = V_63 ;
V_34 . V_24 = V_53 ;
goto V_62;
}
F_31 ( V_18 ) ;
return 0 ;
}
void F_63 ( struct V_4 * V_19 )
{
V_49 V_64 = F_64 ( V_19 -> V_65 . V_66 ) ;
if ( ! ( V_64 & V_67 ) ) {
V_64 |= V_67 ;
V_19 -> V_65 . V_66 = F_65 ( V_64 ) ;
V_19 -> V_66 = 0 ;
V_19 -> V_68 = 0 ;
}
}
void F_66 ( struct V_32 * V_33 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = & V_14 -> V_19 ;
struct V_69 V_70 = V_71 ;
F_67 ( & V_14 -> V_72 ) ;
V_5 -> V_73 = F_65 ( V_33 -> V_74 ) ;
V_5 -> ctime . V_75 = F_65 ( V_70 . V_76 ) ;
V_5 -> ctime . V_77 = F_68 ( V_70 . V_78 ) ;
F_69 ( & V_14 -> V_72 ) ;
}
