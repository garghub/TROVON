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
T_3 V_21 ;
struct V_18 * V_22 ;
int V_7 ;
int V_23 ;
int V_24 ;
F_11 ( sizeof( V_21 ) <= 16 ) ;
for ( V_23 = V_25 ;
V_23 >= V_26 ;
-- V_23 ) {
V_7 = F_12 ( & V_22 , & V_24 ,
V_20 , V_23 ,
V_9 , V_10 ) ;
if ( V_7 != 0 ) {
if ( V_24 )
goto V_27;
continue;
}
F_11 ( V_28 == 1 ) ;
V_21 . V_29 = V_30 ;
V_21 . V_31 = V_28 ;
V_21 . V_32 = V_8 ;
if ( V_33 . V_34 != 0 ) {
F_13 ( V_35 ) ;
if ( ( V_33 . V_34 & 4 ) != 0 ) {
V_21 . V_31 ++ ;
V_33 . V_34 &= ~ 4 ;
}
if ( ( V_33 . V_34 & 8 ) != 0 ) {
V_21 . V_29 = V_36 ;
V_33 . V_34 &= ~ 8 ;
}
F_14 ( V_35 ) ;
}
V_7 = F_15 ( V_22 , & V_21 , sizeof( V_21 ) ,
V_6 ) ;
if ( V_7 != 0 )
goto V_37;
* V_19 = V_22 ;
return 0 ;
}
V_7 = - V_17 ;
goto V_27;
V_37:
F_16 ( V_22 ) ;
V_27:
F_6 ( V_7 , V_8 , V_9 , V_10 ) ;
return V_7 ;
}
static int
F_17 ( struct V_18 * V_22 , T_1 V_2 )
{
T_3 V_21 ;
T_1 V_9 ;
int V_10 ;
int V_7 ;
int V_38 ;
T_4 * V_39 ;
char * V_40 ;
F_18 ( sizeof( V_21 ) <= 16 ) ;
V_7 = F_19 ( V_22 , 1 , & V_9 , & V_10 ) ;
F_18 ( V_7 == 0 ) ;
if ( ! F_2 ( V_2 , V_30 ) ) {
if ( F_2 ( V_2 , V_36 ) ) {
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_29 = V_30 ;
V_21 . V_31 = V_28 ;
V_7 = F_15 ( V_22 , & V_21 , sizeof( V_21 ) ,
V_6 ) ;
if ( V_7 != 0 )
F_20 ( L_8 ,
& V_9 , V_7 ) ;
return - V_16 ;
}
if ( V_2 == F_21 ( V_41 ) )
V_40 = L_9 ;
else if ( F_2 ( V_2 , V_42 ) )
V_40 = L_10 ;
else
V_40 = L_11 ;
F_9 ( 0x11f , L_12 ,
& V_9 , V_2 , V_40 ) ;
return - V_16 ;
}
V_38 = ( V_2 != V_30 ) ;
V_7 = F_22 ( V_22 , & V_21 . V_31 ,
sizeof( V_21 . V_31 ) ,
V_6 ) ;
if ( V_7 != 0 ) {
F_20 ( L_13 ,
V_7 , & V_9 ) ;
return - V_43 ;
}
if ( V_38 )
F_23 ( & V_21 . V_31 ) ;
if ( V_21 . V_31 != V_28 ) {
int V_44 = V_21 . V_31 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_29 = V_30 ;
V_21 . V_31 = V_28 ;
V_7 = F_15 ( V_22 , & V_21 , sizeof( V_21 ) ,
V_6 ) ;
if ( V_7 != 0 )
F_20 ( L_14 ,
V_44 , & V_9 , V_7 ) ;
return - V_16 ;
}
V_7 = F_22 ( V_22 , & V_21 . V_32 ,
sizeof( V_21 ) -
F_24 ( T_3 , V_32 ) ,
V_6 ) ;
if ( V_7 != 0 ) {
F_20 ( L_15 ,
V_7 , & V_9 ) ;
return - V_43 ;
}
if ( V_38 )
F_25 ( & V_21 . V_32 ) ;
V_39 = F_26 ( F_27 ( V_21 . V_32 ) ) ;
if ( V_39 == NULL ||
V_39 -> V_45 != V_21 . V_32 ) {
if ( V_39 != NULL )
F_28 ( V_39 ) ;
F_9 ( 0x120 , L_16 ,
& V_9 , F_8 ( V_21 . V_32 ) ) ;
return - V_46 ;
}
if ( V_39 -> V_47 -> V_48 == NULL ) {
F_28 ( V_39 ) ;
F_9 ( 0x121 , L_17 ,
& V_9 , F_8 ( V_21 . V_32 ) ) ;
return - V_46 ;
}
F_29 ( V_49 , L_18 ,
F_8 ( V_21 . V_32 ) , & V_9 ) ;
V_7 = V_39 -> V_47 -> V_48 ( V_39 , V_22 ) ;
F_28 ( V_39 ) ;
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
int V_52 = ( int ) ( ( V_53 ) V_50 ) ;
F_18 ( V_54 . V_55 == NULL ) ;
F_31 () ;
V_7 = F_32 ( & V_54 . V_55 ,
0 , V_1 , V_56 ) ;
if ( V_7 != 0 ) {
if ( V_7 == - V_17 )
F_9 ( 0x122 , L_19 ,
V_1 ) ;
else
F_9 ( 0x123 , L_20 ,
V_1 , V_7 ) ;
V_54 . V_55 = NULL ;
} else {
F_33 ( 0 , L_21 , V_4 , V_1 ) ;
}
V_54 . V_57 = V_7 ;
F_34 ( & V_54 . V_58 ) ;
if ( V_7 != 0 )
return V_7 ;
while ( ! V_54 . V_57 ) {
V_7 = F_35 ( & V_51 , V_54 . V_55 ) ;
if ( V_7 != 0 ) {
if ( V_7 != - V_59 ) {
F_36 ( L_22 , V_7 ) ;
F_37 ( V_60 ) ;
F_38 ( F_39 ( 1 ) ) ;
}
continue;
}
if ( V_54 . V_57 ) {
F_16 ( V_51 ) ;
break;
}
V_7 = F_19 ( V_51 , 1 , & V_9 , & V_10 ) ;
if ( V_7 != 0 ) {
F_20 ( L_23 ) ;
goto V_27;
}
if ( V_52 && V_10 > V_25 ) {
F_20 ( L_24 ,
& V_9 , V_10 ) ;
goto V_27;
}
V_7 = F_22 ( V_51 , & V_2 , sizeof( V_2 ) ,
V_6 ) ;
if ( V_7 != 0 ) {
F_20 ( L_15 ,
V_7 , & V_9 ) ;
goto V_27;
}
V_7 = F_17 ( V_51 , V_2 ) ;
if ( V_7 != 0 )
goto V_27;
continue;
V_27:
F_16 ( V_51 ) ;
}
F_16 ( V_54 . V_55 ) ;
V_54 . V_55 = NULL ;
F_29 ( V_49 , L_25 ) ;
F_34 ( & V_54 . V_58 ) ;
return 0 ;
}
static inline int
F_40 ( const char * V_61 , long * V_62 )
{
if ( ! strcmp ( V_61 , L_26 ) ) {
* V_62 = 1 ;
return 1 ;
} else if ( ! strcmp ( V_61 , L_27 ) ) {
* V_62 = 0 ;
return 1 ;
} else if ( ! strcmp ( V_61 , L_28 ) ) {
return 0 ;
} else {
F_9 ( 0x124 , L_29 ,
V_61 ) ;
return - V_63 ;
}
}
int
F_41 ( void )
{
int V_7 ;
long V_64 ;
long V_52 ;
F_18 ( V_54 . V_55 == NULL ) ;
V_7 = F_4 () ;
if ( V_7 != 0 )
return V_7 ;
F_42 ( & V_54 . V_58 ) ;
V_7 = F_40 ( V_4 , & V_52 ) ;
if ( V_7 <= 0 )
return V_7 ;
if ( F_43 () == 0 )
return 0 ;
V_64 = F_44 ( F_45 ( F_30 ,
( void * ) ( V_65 ) V_52 ,
L_30 , V_52 ) ) ;
if ( F_46 ( V_64 ) ) {
F_20 ( L_31 , V_64 ) ;
return - V_66 ;
}
F_47 ( & V_54 . V_58 ) ;
if ( ! V_54 . V_57 ) {
F_18 ( V_54 . V_55 != NULL ) ;
return 0 ;
}
F_18 ( V_54 . V_55 == NULL ) ;
return - V_67 ;
}
void
F_48 ( void )
{
if ( V_54 . V_55 == NULL )
return;
V_54 . V_57 = 1 ;
F_49 ( V_54 . V_55 ) ;
F_47 ( & V_54 . V_58 ) ;
}
