static void F_1 ( struct V_1 * V_2 , int V_3 ,
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
F_8 ( V_2 -> V_9 ,
L_1
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
T_2 V_36 ;
V_18 = F_23 () ;
if ( ! V_18 )
return - V_37 ;
V_23 = F_12 ( V_33 , V_14 , V_34 , V_18 , 0 , 1 ) ;
if ( V_23 < 0 ) {
F_24 ( V_33 , V_23 ) ;
goto V_25;
}
if ( V_23 != 0 ) {
F_25 ( V_14 , V_18 -> V_27 [ 0 ] ) ;
F_26 ( V_14 -> V_9 , L_7 ,
V_34 -> V_28 , V_34 -> type , V_34 -> V_24 ) ;
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
F_24 ( V_33 , V_23 ) ;
goto V_25;
}
V_23 = F_27 ( V_33 , V_14 , V_18 ) ;
if ( V_23 < 0 ) {
F_24 ( V_33 , V_23 ) ;
goto V_25;
}
F_15 ( V_18 ) ;
V_23 = F_28 ( V_33 , V_14 , V_18 ,
V_34 , sizeof( * V_5 ) ) ;
if ( V_23 < 0 ) {
F_24 ( V_33 , V_23 ) ;
goto V_25;
}
V_22 = V_18 -> V_27 [ 0 ] ;
V_3 = V_18 -> V_26 [ 0 ] ;
V_35 = F_4 ( V_22 , V_3 ) ;
}
F_29 ( V_5 , F_6 ( V_5 ) ) ;
F_30 ( V_22 , V_5 , V_35 , sizeof( * V_5 ) ) ;
F_31 ( V_18 -> V_27 [ 0 ] ) ;
V_25:
F_32 ( V_18 ) ;
return V_23 ;
}
int F_33 ( struct V_32 * V_33 , struct V_13 * V_14 ,
struct V_15 * V_34 , struct V_4 * V_5 )
{
F_29 ( V_5 , F_6 ( V_5 ) ) ;
return F_34 ( V_33 , V_14 , V_34 , V_5 , sizeof( * V_5 ) ) ;
}
int F_35 ( struct V_13 * V_38 )
{
struct V_1 * V_39 ;
struct V_17 * V_18 ;
struct V_15 V_34 ;
struct V_15 V_20 ;
struct V_13 * V_14 ;
int V_40 = 0 ;
int V_23 ;
bool V_41 = true ;
if ( V_38 -> V_9 -> V_42 -> V_43 & V_44 )
V_41 = false ;
V_18 = F_23 () ;
if ( ! V_18 )
return - V_37 ;
V_34 . V_28 = V_45 ;
V_34 . type = V_46 ;
V_34 . V_24 = 0 ;
V_20 . type = V_29 ;
V_20 . V_24 = ( V_47 ) - 1 ;
while ( 1 ) {
V_23 = F_12 ( NULL , V_38 , & V_34 , V_18 , 0 , 0 ) ;
if ( V_23 < 0 ) {
V_40 = V_23 ;
break;
}
V_39 = V_18 -> V_27 [ 0 ] ;
if ( V_18 -> V_26 [ 0 ] >= F_36 ( V_39 ) ) {
V_23 = F_37 ( V_38 , V_18 ) ;
if ( V_23 < 0 )
V_40 = V_23 ;
if ( V_23 != 0 )
break;
V_39 = V_18 -> V_27 [ 0 ] ;
}
F_14 ( V_39 , & V_34 , V_18 -> V_26 [ 0 ] ) ;
F_15 ( V_18 ) ;
if ( V_34 . V_28 != V_45 ||
V_34 . type != V_46 )
break;
V_20 . V_28 = V_34 . V_24 ;
V_34 . V_24 ++ ;
V_14 = F_38 ( V_38 -> V_9 ,
V_20 . V_28 ) ;
if ( V_14 ) {
F_39 ( ! F_40 ( V_48 ,
& V_14 -> V_49 ) ) ;
if ( F_41 ( & V_14 -> V_19 ) == 0 )
F_42 ( V_14 ) ;
continue;
}
V_14 = F_43 ( V_38 , & V_20 ) ;
V_40 = F_44 ( V_14 ) ;
if ( V_40 && V_40 != - V_50 ) {
break;
} else if ( V_40 == - V_50 ) {
struct V_32 * V_33 ;
F_15 ( V_18 ) ;
V_33 = F_45 ( V_38 ) ;
if ( F_46 ( V_33 ) ) {
V_40 = F_47 ( V_33 ) ;
F_48 ( V_38 -> V_9 , V_40 ,
L_8
L_9 ) ;
break;
}
V_40 = F_49 ( V_33 , V_38 ,
V_20 . V_28 ) ;
F_50 ( V_33 , V_38 ) ;
if ( V_40 ) {
F_48 ( V_38 -> V_9 , V_40 ,
L_10
L_11 ) ;
break;
}
continue;
}
V_40 = F_51 ( V_14 ) ;
if ( V_40 ) {
F_52 ( V_14 ) ;
break;
}
F_53 ( V_48 , & V_14 -> V_49 ) ;
V_40 = F_54 ( V_14 -> V_9 , V_14 ) ;
if ( V_40 ) {
F_13 ( V_40 == - V_51 ) ;
F_52 ( V_14 ) ;
break;
}
if ( F_41 ( & V_14 -> V_19 ) == 0 )
F_42 ( V_14 ) ;
}
F_32 ( V_18 ) ;
return V_40 ;
}
int F_55 ( struct V_32 * V_33 , struct V_13 * V_14 ,
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
V_23 = F_27 ( V_33 , V_14 , V_18 ) ;
V_25:
F_32 ( V_18 ) ;
return V_23 ;
}
int F_56 ( struct V_32 * V_33 ,
struct V_13 * V_38 ,
V_47 V_52 , V_47 V_53 , V_47 V_54 , V_47 * V_55 ,
const char * V_56 , int V_57 )
{
struct V_17 * V_18 ;
struct V_58 * V_59 ;
struct V_1 * V_39 ;
struct V_15 V_34 ;
unsigned long V_35 ;
int V_40 = 0 ;
int V_23 ;
V_18 = F_23 () ;
if ( ! V_18 )
return - V_37 ;
V_34 . V_28 = V_52 ;
V_34 . type = V_60 ;
V_34 . V_24 = V_53 ;
V_61:
V_23 = F_12 ( V_33 , V_38 , & V_34 , V_18 , - 1 , 1 ) ;
F_13 ( V_23 < 0 ) ;
if ( V_23 == 0 ) {
V_39 = V_18 -> V_27 [ 0 ] ;
V_59 = F_57 ( V_39 , V_18 -> V_26 [ 0 ] ,
struct V_58 ) ;
F_39 ( F_58 ( V_39 , V_59 ) != V_54 ) ;
F_39 ( F_59 ( V_39 , V_59 ) != V_57 ) ;
V_35 = ( unsigned long ) ( V_59 + 1 ) ;
F_39 ( F_60 ( V_39 , V_56 , V_35 , V_57 ) ) ;
* V_55 = F_61 ( V_39 , V_59 ) ;
V_23 = F_27 ( V_33 , V_38 , V_18 ) ;
if ( V_23 ) {
V_40 = V_23 ;
goto V_25;
}
} else
V_40 = - V_50 ;
if ( V_34 . type == V_60 ) {
F_15 ( V_18 ) ;
V_34 . V_28 = V_53 ;
V_34 . type = V_62 ;
V_34 . V_24 = V_52 ;
goto V_61;
}
V_25:
F_32 ( V_18 ) ;
return V_40 ;
}
int F_62 ( struct V_32 * V_33 ,
struct V_13 * V_38 ,
V_47 V_52 , V_47 V_53 , V_47 V_54 , V_47 V_55 ,
const char * V_56 , int V_57 )
{
struct V_15 V_34 ;
int V_23 ;
struct V_17 * V_18 ;
struct V_58 * V_59 ;
struct V_1 * V_39 ;
unsigned long V_35 ;
V_18 = F_23 () ;
if ( ! V_18 )
return - V_37 ;
V_34 . V_28 = V_52 ;
V_34 . type = V_60 ;
V_34 . V_24 = V_53 ;
V_61:
V_23 = F_28 ( V_33 , V_38 , V_18 , & V_34 ,
sizeof( * V_59 ) + V_57 ) ;
if ( V_23 ) {
F_24 ( V_33 , V_23 ) ;
F_32 ( V_18 ) ;
return V_23 ;
}
V_39 = V_18 -> V_27 [ 0 ] ;
V_59 = F_57 ( V_39 , V_18 -> V_26 [ 0 ] , struct V_58 ) ;
F_63 ( V_39 , V_59 , V_54 ) ;
F_64 ( V_39 , V_59 , V_55 ) ;
F_65 ( V_39 , V_59 , V_57 ) ;
V_35 = ( unsigned long ) ( V_59 + 1 ) ;
F_30 ( V_39 , V_56 , V_35 , V_57 ) ;
F_31 ( V_39 ) ;
if ( V_34 . type == V_60 ) {
F_15 ( V_18 ) ;
V_34 . V_28 = V_53 ;
V_34 . type = V_62 ;
V_34 . V_24 = V_52 ;
goto V_61;
}
F_32 ( V_18 ) ;
return 0 ;
}
void F_66 ( struct V_4 * V_19 )
{
V_47 V_63 = F_67 ( & V_19 -> V_64 ) ;
if ( ! ( V_63 & V_65 ) ) {
V_63 |= V_65 ;
F_68 ( & V_19 -> V_64 , V_63 ) ;
F_69 ( V_19 , 0 ) ;
F_70 ( V_19 , 0 ) ;
}
}
void F_71 ( struct V_32 * V_33 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = & V_14 -> V_19 ;
struct V_66 V_67 = F_72 ( V_14 -> V_9 -> V_42 ) ;
F_73 ( & V_14 -> V_68 ) ;
F_74 ( V_5 , V_33 -> V_69 ) ;
F_75 ( & V_5 -> ctime , V_67 . V_70 ) ;
F_76 ( & V_5 -> ctime , V_67 . V_71 ) ;
F_77 ( & V_14 -> V_68 ) ;
}
