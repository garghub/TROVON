static T_1 int F_1 ( void )
{
int V_1 = V_2 ;
if ( V_1 != V_3 )
return V_1 ;
switch ( V_4 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
return V_9 ;
case V_10 :
case V_11 :
case V_12 :
return V_13 ;
case V_14 :
case V_15 :
case V_16 :
return V_17 ;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
default:
return V_22 ;
}
}
static unsigned T_1 F_2 ( T_2 * V_23 , unsigned long V_24 ,
enum V_25 V_26 )
{
unsigned long V_27 ;
unsigned V_28 ;
V_28 = 1 ;
V_23 [ 0 ] = F_3 ( V_29 ) ;
if ( F_4 ( V_30 ) ) {
V_23 [ 1 ] = F_3 ( V_24 ) ;
goto V_31;
}
V_27 = F_5 (unsigned long, size, SZ_256M) ;
V_23 [ 1 ] = F_3 ( V_27 ) ;
V_24 -= V_27 ;
if ( ! V_24 )
goto V_31;
if ( V_26 == V_32 ) {
if ( V_24 <= V_33 )
goto V_31;
V_24 -= V_33 ;
V_28 ++ ;
V_23 [ 2 ] = F_3 ( V_29 + V_34 ) ;
V_23 [ 3 ] = F_3 ( V_24 ) ;
} else {
V_28 ++ ;
V_23 [ 2 ] = F_3 ( V_29 + V_35 + V_33 ) ;
V_23 [ 3 ] = F_3 ( V_24 ) ;
}
V_31:
F_6 ( V_28 > V_36 ) ;
return V_28 ;
}
static void T_1 F_7 ( void * V_37 , int V_38 )
{
T_2 V_23 [ 2 * V_36 ] ;
unsigned long V_39 ;
unsigned V_40 ;
int V_41 , V_42 , V_43 ;
enum V_25 V_25 ;
T_3 V_44 ;
char * V_45 , V_46 [ 10 ] , * V_47 [] = {
L_1 , L_2 ,
} ;
V_43 = F_8 ( V_37 , L_3 ) ;
if ( V_43 >= 0 )
return;
for ( V_41 = 0 ; V_41 < F_9 ( V_47 ) ; V_41 ++ ) {
V_45 = F_10 ( V_47 [ V_41 ] ) ;
if ( ! V_45 )
continue;
V_42 = F_11 ( V_45 , 0 , & V_48 ) ;
if ( ! V_42 )
break;
F_12 ( L_4 ,
V_47 [ V_41 ] , V_45 ) ;
}
if ( ! V_48 ) {
F_12 ( L_5 ) ;
V_48 = 32 << 20 ;
}
if ( F_4 ( V_49 ) ) {
V_48 -= V_50 ;
}
V_39 = V_48 ;
for ( V_41 = 0 ; V_41 < F_9 ( V_47 ) ; V_41 ++ ) {
snprintf ( V_46 , sizeof( V_46 ) , L_6 , V_47 [ V_41 ] ) ;
V_45 = strstr ( V_51 , V_46 ) ;
if ( ! V_45 )
continue;
V_39 = F_13 ( V_45 + strlen ( V_46 ) , NULL ) ;
}
V_48 = F_14 (unsigned long, physical_memsize, memsize) ;
if ( F_1 () == V_22 ) {
V_44 = F_15 ( ( void V_52 * ) F_16 ( V_53 ) ) ;
V_25 = V_44 & V_54 ;
V_25 >>= V_55 ;
} else {
V_25 = V_56 ;
}
if ( V_25 > V_32 )
F_17 ( L_7 ,
( unsigned int ) V_25 ) ;
V_43 = F_18 ( V_37 , V_38 , L_8 ) ;
if ( V_43 < 0 )
F_17 ( L_9 , V_43 ) ;
V_42 = F_19 ( V_37 , V_43 , L_10 , L_8 ) ;
if ( V_42 )
F_17 ( L_11 , V_42 ) ;
V_40 = F_2 ( V_23 , V_48 , V_25 ) ;
V_42 = F_20 ( V_37 , V_43 , L_12 , V_23 ,
V_40 * 2 * sizeof( V_23 [ 0 ] ) ) ;
if ( V_42 )
F_17 ( L_13 , V_42 ) ;
V_40 = F_2 ( V_23 , V_39 , V_25 ) ;
V_42 = F_20 ( V_37 , V_43 , L_14 , V_23 ,
V_40 * 2 * sizeof( V_23 [ 0 ] ) ) ;
if ( V_42 )
F_17 ( L_15 , V_42 ) ;
}
static void T_1 F_21 ( void * V_37 )
{
int V_42 , V_57 , V_58 , V_59 ;
void V_52 * V_60 ;
T_4 V_61 , V_62 ;
V_42 = F_22 () ;
if ( ! V_42 && ( F_23 () & V_63 ) )
return;
if ( F_1 () == V_22 ) {
V_60 = F_24 ( V_64 ,
V_65 ) ;
V_62 = F_25 ( V_60 + V_66 ) ;
if ( V_62 & V_67 ) {
V_62 |= F_26 ( V_68 ) ;
F_27 ( V_62 , V_60 + V_66 ) ;
return;
}
}
V_57 = F_28 ( V_37 , - 1 , L_16 ) ;
if ( V_57 < 0 ) {
F_12 ( L_17 ,
V_57 ) ;
return;
}
V_42 = F_29 ( V_37 , V_57 ) ;
if ( V_42 )
F_12 ( L_18 ) ;
V_58 = F_28 ( V_37 , - 1 , L_19 ) ;
if ( V_58 < 0 ) {
F_12 ( L_20 ,
V_58 ) ;
return;
}
V_59 = F_28 ( V_37 , - 1 ,
L_21 ) ;
if ( V_59 < 0 ) {
F_12 ( L_22 ,
V_59 ) ;
return;
}
V_61 = F_30 ( V_37 , V_59 ) ;
if ( ! V_61 ) {
F_12 ( L_23 ) ;
return;
}
V_42 = F_31 ( V_37 , V_58 , L_24 , V_61 ) ;
if ( V_42 ) {
F_12 ( L_25 ,
V_42 ) ;
return;
}
V_42 = F_31 ( V_37 , V_58 , L_26 , 2 ) ;
if ( V_42 ) {
F_12 ( L_27 ,
V_42 ) ;
return;
}
}
void T_1 * F_32 ( void * V_37 )
{
int V_38 , V_69 , V_42 ;
const char * V_70 ;
if ( F_33 ( V_37 ) )
F_17 ( L_28 ) ;
V_42 = F_34 ( V_37 , V_71 , sizeof( V_71 ) ) ;
if ( V_42 )
F_17 ( L_29 , V_42 ) ;
V_38 = F_8 ( V_71 , L_30 ) ;
if ( V_38 < 0 )
F_17 ( L_31 ) ;
V_70 = F_35 ( V_71 , V_38 , L_32 , & V_69 ) ;
if ( ! V_70 )
F_17 ( L_33 , V_69 ) ;
if ( strncmp ( V_70 , L_34 , V_69 ) )
return V_37 ;
F_7 ( V_71 , V_38 ) ;
F_21 ( V_71 ) ;
V_42 = F_36 ( V_71 ) ;
if ( V_42 )
F_17 ( L_35 , V_42 ) ;
return V_71 ;
}
