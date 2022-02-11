int
F_1 ( void )
{
return V_1 ;
}
static inline int
F_2 ( T_1 V_2 , T_1 V_3 )
{
return ( V_2 == V_3 ||
V_2 == F_3 ( V_3 ) ) ;
}
static int
F_4 ( void )
{
V_4 = V_5 ;
return 0 ;
}
int
F_5 ( void )
{
return V_6 ;
}
void
F_6 ( int V_7 , T_2 V_8 ,
T_1 V_9 , int V_10 )
{
switch ( V_7 ) {
case - V_11 :
F_7 ( L_1 ,
F_8 ( V_8 ) ,
& V_9 , V_10 ) ;
break;
case - V_12 :
case - V_13 :
F_7 ( L_2 ,
F_8 ( V_8 ) , & V_9 ) ;
break;
case - V_14 :
F_7 ( L_3 ,
F_8 ( V_8 ) ,
& V_9 , V_10 ) ;
break;
case - V_15 :
F_9 ( 0x11b , L_4 ,
F_8 ( V_8 ) ,
& V_9 , V_10 ,
F_8 ( V_8 ) ) ;
break;
case - V_16 :
F_9 ( 0x11c , L_5 ,
F_8 ( V_8 ) ,
& V_9 , V_10 ) ;
break;
case - V_17 :
F_9 ( 0x11d , L_6 ,
F_8 ( V_8 ) ,
& V_9 , V_10 ) ;
break;
default:
F_9 ( 0x11e , L_7 ,
V_7 , F_8 ( V_8 ) ,
& V_9 , V_10 ) ;
break;
}
}
int
F_10 ( struct V_18 * * V_19 , T_2 V_8 ,
T_1 V_20 , T_1 V_9 , int V_10 )
{
struct V_21 V_22 ;
struct V_18 * V_23 ;
int V_7 ;
int V_24 ;
int V_25 ;
F_11 ( sizeof( V_22 ) > 16 ) ;
for ( V_24 = V_26 ;
V_24 >= V_27 ;
-- V_24 ) {
V_7 = F_12 ( & V_23 , & V_25 , V_20 , V_24 , V_9 ,
V_10 ) ;
if ( V_7 ) {
if ( V_25 )
goto V_28;
continue;
}
F_11 ( V_29 != 1 ) ;
V_22 . V_30 = V_31 ;
V_22 . V_32 = V_29 ;
V_22 . V_33 = V_8 ;
if ( V_34 . V_35 ) {
F_13 ( V_36 ) ;
if ( V_34 . V_35 & 4 ) {
V_22 . V_32 ++ ;
V_34 . V_35 &= ~ 4 ;
}
if ( V_34 . V_35 & 8 ) {
V_22 . V_30 = V_37 ;
V_34 . V_35 &= ~ 8 ;
}
F_14 ( V_36 ) ;
}
V_7 = F_15 ( V_23 , & V_22 , sizeof( V_22 ) , V_6 ) ;
if ( V_7 )
goto V_38;
* V_19 = V_23 ;
return 0 ;
}
V_7 = - V_17 ;
goto V_28;
V_38:
F_16 ( V_23 ) ;
V_28:
F_6 ( V_7 , V_8 , V_9 , V_10 ) ;
return V_7 ;
}
static int
F_17 ( struct V_18 * V_23 , T_1 V_2 )
{
struct V_21 V_22 ;
T_1 V_9 ;
int V_10 ;
int V_7 ;
int V_39 ;
T_3 * V_40 ;
char * V_41 ;
F_18 ( sizeof( V_22 ) <= 16 ) ;
V_7 = F_19 ( V_23 , 1 , & V_9 , & V_10 ) ;
F_18 ( ! V_7 ) ;
if ( ! F_2 ( V_2 , V_31 ) ) {
if ( F_2 ( V_2 , V_37 ) ) {
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_30 = V_31 ;
V_22 . V_32 = V_29 ;
V_7 = F_15 ( V_23 , & V_22 , sizeof( V_22 ) ,
V_6 ) ;
if ( V_7 )
F_20 ( L_8 ,
& V_9 , V_7 ) ;
return - V_16 ;
}
if ( V_2 == F_21 ( V_42 ) )
V_41 = L_9 ;
else
V_41 = L_10 ;
F_9 ( 0x11f , L_11 ,
& V_9 , V_2 , V_41 ) ;
return - V_16 ;
}
V_39 = ( V_2 != V_31 ) ;
V_7 = F_22 ( V_23 , & V_22 . V_32 , sizeof( V_22 . V_32 ) ,
V_6 ) ;
if ( V_7 ) {
F_20 ( L_12 ,
V_7 , & V_9 ) ;
return - V_43 ;
}
if ( V_39 )
F_23 ( & V_22 . V_32 ) ;
if ( V_22 . V_32 != V_29 ) {
int V_44 = V_22 . V_32 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_30 = V_31 ;
V_22 . V_32 = V_29 ;
V_7 = F_15 ( V_23 , & V_22 , sizeof( V_22 ) , V_6 ) ;
if ( V_7 )
F_20 ( L_13 ,
V_44 , & V_9 , V_7 ) ;
return - V_16 ;
}
V_7 = F_22 ( V_23 , & V_22 . V_33 ,
sizeof( V_22 ) -
F_24 ( struct V_21 , V_33 ) ,
V_6 ) ;
if ( V_7 ) {
F_20 ( L_14 ,
V_7 , & V_9 ) ;
return - V_43 ;
}
if ( V_39 )
F_25 ( & V_22 . V_33 ) ;
V_40 = F_26 ( F_27 ( V_22 . V_33 ) ) ;
if ( ! V_40 ||
V_40 -> V_45 != V_22 . V_33 ) {
if ( V_40 )
F_28 ( V_40 ) ;
F_9 ( 0x120 , L_15 ,
& V_9 , F_8 ( V_22 . V_33 ) ) ;
return - V_46 ;
}
if ( ! V_40 -> V_47 -> V_48 ) {
F_28 ( V_40 ) ;
F_9 ( 0x121 , L_16 ,
& V_9 , F_8 ( V_22 . V_33 ) ) ;
return - V_46 ;
}
F_29 ( V_49 , L_17 ,
F_8 ( V_22 . V_33 ) , & V_9 ) ;
V_7 = V_40 -> V_47 -> V_48 ( V_40 , V_23 ) ;
F_28 ( V_40 ) ;
return V_7 ;
}
static int
F_30 ( void * V_50 )
{
struct V_18 * V_51 ;
int V_7 ;
T_1 V_2 ;
T_1 V_9 ;
int V_10 ;
int V_52 = ( int ) ( ( long ) V_50 ) ;
F_18 ( ! V_53 . V_54 ) ;
F_31 () ;
V_7 = F_32 ( & V_53 . V_54 , 0 , V_1 ,
V_55 ) ;
if ( V_7 ) {
if ( V_7 == - V_17 )
F_9 ( 0x122 , L_18 ,
V_1 ) ;
else
F_9 ( 0x123 , L_19 ,
V_1 , V_7 ) ;
V_53 . V_54 = NULL ;
} else {
F_33 ( 0 , L_20 , V_4 , V_1 ) ;
}
V_53 . V_56 = V_7 ;
F_34 ( & V_53 . V_57 ) ;
if ( V_7 )
return V_7 ;
while ( ! V_53 . V_56 ) {
V_7 = F_35 ( & V_51 , V_53 . V_54 ) ;
if ( V_7 ) {
if ( V_7 != - V_58 ) {
F_36 ( L_21 , V_7 ) ;
F_37 ( V_59 ) ;
F_38 ( F_39 ( 1 ) ) ;
}
continue;
}
if ( V_53 . V_56 ) {
F_16 ( V_51 ) ;
break;
}
V_7 = F_19 ( V_51 , 1 , & V_9 , & V_10 ) ;
if ( V_7 ) {
F_20 ( L_22 ) ;
goto V_28;
}
if ( V_52 && V_10 > V_26 ) {
F_20 ( L_23 ,
& V_9 , V_10 ) ;
goto V_28;
}
V_7 = F_22 ( V_51 , & V_2 , sizeof( V_2 ) ,
V_6 ) ;
if ( V_7 ) {
F_20 ( L_14 ,
V_7 , & V_9 ) ;
goto V_28;
}
V_7 = F_17 ( V_51 , V_2 ) ;
if ( V_7 )
goto V_28;
continue;
V_28:
F_16 ( V_51 ) ;
}
F_16 ( V_53 . V_54 ) ;
V_53 . V_54 = NULL ;
F_29 ( V_49 , L_24 ) ;
F_34 ( & V_53 . V_57 ) ;
return 0 ;
}
static inline int
F_40 ( const char * V_60 , long * V_61 )
{
if ( ! strcmp ( V_60 , L_25 ) ) {
* V_61 = 1 ;
return 1 ;
} else if ( ! strcmp ( V_60 , L_26 ) ) {
* V_61 = 0 ;
return 1 ;
} else if ( ! strcmp ( V_60 , L_27 ) ) {
return 0 ;
}
F_9 ( 0x124 , L_28 ,
V_60 ) ;
return - V_62 ;
}
int
F_41 ( void )
{
struct V_63 * V_64 ;
int V_7 ;
long V_65 ;
long V_52 ;
if ( ! V_53 . V_56 )
return 0 ;
F_18 ( ! V_53 . V_54 ) ;
V_7 = F_4 () ;
if ( V_7 )
return V_7 ;
F_42 ( & V_53 . V_57 ) ;
V_7 = F_40 ( V_4 , & V_52 ) ;
if ( V_7 <= 0 )
return V_7 ;
if ( ! F_43 () )
return 0 ;
V_64 = F_44 ( F_30 , ( void * ) ( V_66 ) V_52 ,
L_29 , V_52 ) ;
if ( F_45 ( V_64 ) ) {
V_65 = F_46 ( V_64 ) ;
F_20 ( L_30 , V_65 ) ;
return - V_67 ;
}
F_47 ( & V_53 . V_57 ) ;
if ( ! V_53 . V_56 ) {
F_18 ( V_53 . V_54 ) ;
return 0 ;
}
F_18 ( ! V_53 . V_54 ) ;
return - V_68 ;
}
void
F_48 ( void )
{
struct V_23 * V_69 ;
if ( V_53 . V_56 )
return;
V_53 . V_56 = 1 ;
V_69 = V_53 . V_54 -> V_69 ;
V_69 -> V_70 ( V_69 ) ;
F_47 ( & V_53 . V_57 ) ;
}
