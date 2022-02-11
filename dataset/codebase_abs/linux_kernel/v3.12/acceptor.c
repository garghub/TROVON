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
int
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
F_7 ( L_1
L_2 ,
F_8 ( V_8 ) ,
& V_9 , V_10 ) ;
break;
case - V_12 :
case - V_13 :
F_7 ( L_3
L_4
L_5 ,
F_8 ( V_8 ) , & V_9 ) ;
break;
case - V_14 :
F_7 ( L_6
L_7
L_8 ,
F_8 ( V_8 ) ,
& V_9 , V_10 ) ;
break;
case - V_15 :
F_9 ( 0x11b , L_9
L_10
L_11
L_12 ,
F_8 ( V_8 ) ,
& V_9 , V_10 ,
F_8 ( V_8 ) ) ;
break;
case - V_16 :
F_9 ( 0x11c , L_13
L_14
L_15 ,
F_8 ( V_8 ) ,
& V_9 , V_10 ) ;
break;
case - V_17 :
F_9 ( 0x11d , L_16
L_17
L_18 , F_8 ( V_8 ) ,
& V_9 , V_10 ) ;
break;
default:
F_9 ( 0x11e , L_19
L_20 , V_7 ,
F_8 ( V_8 ) ,
& V_9 , V_10 ) ;
break;
}
}
int
F_10 ( T_3 * * V_18 , T_2 V_8 ,
T_1 V_19 , T_1 V_9 , int V_10 )
{
T_4 V_20 ;
T_3 * V_21 ;
int V_7 ;
int V_22 ;
int V_23 ;
F_11 ( sizeof( V_20 ) <= 16 ) ;
for ( V_22 = V_24 ;
V_22 >= V_25 ;
-- V_22 ) {
V_7 = F_12 ( & V_21 , & V_23 ,
V_19 , V_22 ,
V_9 , V_10 ) ;
if ( V_7 != 0 ) {
if ( V_23 )
goto V_26;
continue;
}
F_11 ( V_27 == 1 ) ;
V_20 . V_28 = V_29 ;
V_20 . V_30 = V_27 ;
V_20 . V_31 = V_8 ;
if ( V_32 . V_33 != 0 ) {
F_13 ( V_34 ) ;
if ( ( V_32 . V_33 & 4 ) != 0 ) {
V_20 . V_30 ++ ;
V_32 . V_33 &= ~ 4 ;
}
if ( ( V_32 . V_33 & 8 ) != 0 ) {
V_20 . V_28 = V_35 ;
V_32 . V_33 &= ~ 8 ;
}
F_14 ( V_34 ) ;
}
V_7 = F_15 ( V_21 , & V_20 , sizeof( V_20 ) ,
V_6 ) ;
if ( V_7 != 0 )
goto V_36;
* V_18 = V_21 ;
return 0 ;
}
V_7 = - V_17 ;
goto V_26;
V_36:
F_16 ( V_21 ) ;
V_26:
F_6 ( V_7 , V_8 , V_9 , V_10 ) ;
return V_7 ;
}
int
F_17 ( T_3 * V_21 , T_1 V_2 )
{
T_4 V_20 ;
T_1 V_9 ;
int V_10 ;
int V_7 ;
int V_37 ;
T_5 * V_38 ;
char * V_39 ;
F_18 ( sizeof( V_20 ) <= 16 ) ;
V_7 = F_19 ( V_21 , 1 , & V_9 , & V_10 ) ;
F_18 ( V_7 == 0 ) ;
if ( ! F_2 ( V_2 , V_29 ) ) {
if ( F_2 ( V_2 , V_35 ) ) {
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_28 = V_29 ;
V_20 . V_30 = V_27 ;
V_7 = F_15 ( V_21 , & V_20 , sizeof( V_20 ) ,
V_6 ) ;
if ( V_7 != 0 )
F_20 ( L_21
L_22 ,
& V_9 , V_7 ) ;
return - V_16 ;
}
if ( V_2 == F_21 ( V_40 ) )
V_39 = L_23 ;
else if ( F_2 ( V_2 , V_41 ) )
V_39 = L_24 ;
else
V_39 = L_25 ;
F_9 ( 0x11f , L_26
L_27 ,
& V_9 , V_2 , V_39 ) ;
return - V_16 ;
}
V_37 = ( V_2 != V_29 ) ;
V_7 = F_22 ( V_21 , & V_20 . V_30 ,
sizeof( V_20 . V_30 ) ,
V_6 ) ;
if ( V_7 != 0 ) {
F_20 ( L_28
L_29 , V_7 , & V_9 ) ;
return - V_42 ;
}
if ( V_37 )
F_23 ( & V_20 . V_30 ) ;
if ( V_20 . V_30 != V_27 ) {
int V_43 = V_20 . V_30 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_28 = V_29 ;
V_20 . V_30 = V_27 ;
V_7 = F_15 ( V_21 , & V_20 , sizeof( V_20 ) ,
V_6 ) ;
if ( V_7 != 0 )
F_20 ( L_21
L_30 ,
V_43 , & V_9 , V_7 ) ;
return - V_16 ;
}
V_7 = F_22 ( V_21 , & V_20 . V_31 ,
sizeof( V_20 ) -
F_24 ( T_4 , V_31 ) ,
V_6 ) ;
if ( V_7 != 0 ) {
F_20 ( L_31
L_29 , V_7 , & V_9 ) ;
return - V_42 ;
}
if ( V_37 )
F_25 ( & V_20 . V_31 ) ;
V_38 = F_26 ( F_27 ( V_20 . V_31 ) ) ;
if ( V_38 == NULL ||
V_38 -> V_44 != V_20 . V_31 ) {
if ( V_38 != NULL )
F_28 ( V_38 ) ;
F_9 ( 0x120 , L_26
L_32 ,
& V_9 , F_8 ( V_20 . V_31 ) ) ;
return - V_45 ;
}
if ( V_38 -> V_46 -> V_47 == NULL ) {
F_28 ( V_38 ) ;
F_9 ( 0x121 , L_26
L_33 ,
& V_9 , F_8 ( V_20 . V_31 ) ) ;
return - V_45 ;
}
F_29 ( V_48 , L_34 ,
F_8 ( V_20 . V_31 ) , & V_9 ) ;
V_7 = V_38 -> V_46 -> V_47 ( V_38 , V_21 ) ;
F_28 ( V_38 ) ;
return V_7 ;
}
int
F_30 ( void * V_49 )
{
T_3 * V_50 ;
int V_7 ;
T_1 V_2 ;
T_1 V_9 ;
int V_10 ;
int V_51 = ( int ) ( ( V_52 ) V_49 ) ;
F_18 ( V_53 . V_54 == NULL ) ;
F_31 () ;
V_7 = F_32 ( & V_53 . V_54 ,
0 , V_1 , V_55 ) ;
if ( V_7 != 0 ) {
if ( V_7 == - V_17 )
F_9 ( 0x122 , L_35
L_36 ,
V_1 ) ;
else
F_9 ( 0x123 , L_37
L_38 ,
V_1 , V_7 ) ;
V_53 . V_54 = NULL ;
} else {
F_33 ( 0 , L_39 , V_4 , V_1 ) ;
}
V_53 . V_56 = V_7 ;
F_34 ( & V_53 . V_57 ) ;
if ( V_7 != 0 )
return V_7 ;
while ( ! V_53 . V_56 ) {
V_7 = F_35 ( & V_50 , V_53 . V_54 ) ;
if ( V_7 != 0 ) {
if ( V_7 != - V_58 ) {
F_36 ( L_40 , V_7 ) ;
F_37 ( F_38 ( 1 ) ) ;
}
continue;
}
if ( V_53 . V_56 ) {
F_16 ( V_50 ) ;
break;
}
V_7 = F_19 ( V_50 , 1 , & V_9 , & V_10 ) ;
if ( V_7 != 0 ) {
F_20 ( L_41 ) ;
goto V_26;
}
if ( V_51 && V_10 > V_24 ) {
F_20 ( L_42
L_43 ,
& V_9 , V_10 ) ;
goto V_26;
}
V_7 = F_22 ( V_50 , & V_2 , sizeof( V_2 ) ,
V_6 ) ;
if ( V_7 != 0 ) {
F_20 ( L_31
L_29 , V_7 , & V_9 ) ;
goto V_26;
}
V_7 = F_17 ( V_50 , V_2 ) ;
if ( V_7 != 0 )
goto V_26;
continue;
V_26:
F_16 ( V_50 ) ;
}
F_16 ( V_53 . V_54 ) ;
V_53 . V_54 = NULL ;
F_29 ( V_48 , L_44 ) ;
F_34 ( & V_53 . V_57 ) ;
return 0 ;
}
static inline int
F_39 ( const char * V_59 , long * V_60 )
{
if ( ! strcmp ( V_59 , L_45 ) ) {
* V_60 = 1 ;
return 1 ;
} else if ( ! strcmp ( V_59 , L_46 ) ) {
* V_60 = 0 ;
return 1 ;
} else if ( ! strcmp ( V_59 , L_47 ) ) {
return 0 ;
} else {
F_9 ( 0x124 , L_48 ,
V_59 ) ;
return - V_61 ;
}
}
int
F_40 ( void )
{
int V_7 ;
long V_62 ;
long V_51 ;
F_18 ( V_53 . V_54 == NULL ) ;
V_7 = F_4 () ;
if ( V_7 != 0 )
return V_7 ;
F_41 ( & V_53 . V_57 ) ;
V_7 = F_39 ( V_4 , & V_51 ) ;
if ( V_7 <= 0 ) {
F_42 ( & V_53 . V_57 ) ;
return V_7 ;
}
if ( F_43 () == 0 )
return 0 ;
V_62 = F_44 ( F_45 ( F_30 ,
( void * ) ( V_63 ) V_51 ,
L_49 , V_51 ) ) ;
if ( F_46 ( V_62 ) ) {
F_20 ( L_50 , V_62 ) ;
F_42 ( & V_53 . V_57 ) ;
return - V_64 ;
}
F_47 ( & V_53 . V_57 ) ;
if ( ! V_53 . V_56 ) {
F_18 ( V_53 . V_54 != NULL ) ;
return 0 ;
}
F_18 ( V_53 . V_54 == NULL ) ;
F_42 ( & V_53 . V_57 ) ;
return - V_65 ;
}
void
F_48 ( void )
{
if ( V_53 . V_54 == NULL )
return;
V_53 . V_56 = 1 ;
F_49 ( V_53 . V_54 ) ;
F_47 ( & V_53 . V_57 ) ;
F_42 ( & V_53 . V_57 ) ;
}
