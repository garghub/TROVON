static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 ;
if ( ! V_2 -> V_8 )
V_2 -> V_8 = 1 ;
if ( ! V_2 -> V_9 )
V_2 -> V_9 = 1 ;
if ( V_2 -> V_10 <= 8 )
V_2 -> V_10 = 8 ;
else if ( V_2 -> V_10 <= 16 )
V_2 -> V_10 = 16 ;
else if ( V_2 -> V_10 <= 24 )
V_2 -> V_10 = 24 ;
else if ( V_2 -> V_10 <= 32 )
V_2 -> V_10 = 32 ;
else
return - V_11 ;
V_2 -> V_12 = V_2 -> V_8 ;
V_2 -> V_13 = 2 * V_2 -> V_9 ;
if ( V_4 -> V_14 . V_15 ) {
if ( ( V_2 -> V_13 * V_2 -> V_12 * V_2 -> V_10 / 8 ) > V_4 -> V_14 . V_15 )
return - V_16 ;
}
for ( V_7 = 0 ; V_7 <= 3 ; V_7 ++ ) {
if ( V_2 -> V_17 == V_6 -> V_18 -> V_19 [ V_7 ] )
break;
}
if ( V_7 <= 3 )
V_6 -> V_20 = V_7 ;
else
return - V_11 ;
switch ( V_4 -> V_2 . V_10 ) {
case 8 :
V_2 -> V_21 = (struct V_22 ) { 0 , 8 , 0 } ;
V_2 -> V_23 = (struct V_22 ) { 0 , 8 , 0 } ;
V_2 -> V_24 = (struct V_22 ) { 0 , 8 , 0 } ;
V_2 -> V_25 = (struct V_22 ) { 0 , 0 , 0 } ;
break;
case 16 :
V_2 -> V_21 = (struct V_22 ) { 11 , 5 , 0 } ;
V_2 -> V_23 = (struct V_22 ) { 5 , 6 , 0 } ;
V_2 -> V_24 = (struct V_22 ) { 0 , 5 , 0 } ;
V_2 -> V_25 = (struct V_22 ) { 0 , 0 , 0 } ;
break;
case 24 :
case 32 :
V_2 -> V_21 = (struct V_22 ) { 16 , 8 , 0 } ;
V_2 -> V_23 = (struct V_22 ) { 8 , 8 , 0 } ;
V_2 -> V_24 = (struct V_22 ) { 0 , 8 , 0 } ;
V_2 -> V_25 = (struct V_22 ) { 24 , 8 , 0 } ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static int F_2 ( struct V_3 * V_4 )
{
T_1 V_26 = 0 ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_3 ( ( ( V_4 -> V_2 . V_9 - 1 ) << 16 ) | ( V_4 -> V_2 . V_8 - 1 ) ,
& V_6 -> V_18 -> V_27 ) ;
F_3 ( ( V_4 -> V_2 . V_28 << 16 ) | ( V_4 -> V_2 . V_29 ) ,
& V_6 -> V_18 -> V_30 ) ;
F_3 ( ( V_4 -> V_2 . V_31 << 16 ) | ( V_4 -> V_2 . V_32 ) ,
& V_6 -> V_18 -> V_33 ) ;
F_3 ( ( ( V_4 -> V_2 . V_9 + V_4 -> V_2 . V_28 + V_4 -> V_2 . V_34 + V_4 -> V_2 . V_31 - 1 ) << 16 ) |
( V_4 -> V_2 . V_8 + V_4 -> V_2 . V_29 + V_4 -> V_2 . V_35 + V_4 -> V_2 . V_32 - 1 ) ,
& V_6 -> V_18 -> V_36 ) ;
switch ( V_4 -> V_2 . V_10 ) {
case 8 :
V_4 -> V_14 . V_37 = V_38 ;
V_26 = 1 ;
break;
case 16 :
V_4 -> V_14 . V_37 = V_39 ;
V_26 = 2 ;
break;
case 24 :
case 32 :
V_4 -> V_14 . V_37 = V_39 ;
V_26 = 3 ;
break;
default:
return - V_11 ;
}
F_3 ( ( V_6 -> V_20 << 6 ) | ( V_26 << 4 ) | 1 ,
& V_6 -> V_18 -> V_40 ) ;
V_4 -> V_14 . V_36 = ( V_4 -> V_2 . V_12 * V_4 -> V_2 . V_10 ) / 8 ;
return 0 ;
}
static int F_4 ( unsigned V_41 , unsigned V_21 , unsigned V_23 , unsigned V_24 , unsigned V_25 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = V_4 -> V_6 ;
if ( V_41 >= 256 )
return - V_11 ;
if ( V_4 -> V_2 . V_42 ) {
V_21 = V_23 = V_24 = ( V_21 * 77 + V_23 * 151 + V_24 * 28 ) >> 8 ;
}
#define F_5 ( T_2 , T_3 ) ((((val)<<(width))+0x7FFF-(val))>>16)
V_21 = F_5 ( V_21 , V_4 -> V_2 . V_21 . V_43 ) ;
V_23 = F_5 ( V_23 , V_4 -> V_2 . V_23 . V_43 ) ;
V_24 = F_5 ( V_24 , V_4 -> V_2 . V_24 . V_43 ) ;
V_25 = F_5 ( V_25 , V_4 -> V_2 . V_25 . V_43 ) ;
#undef F_5
if ( V_4 -> V_14 . V_37 == V_38 )
F_3 ( ( V_41 << 24 ) | ( V_21 << 16 ) | ( V_23 << 8 ) | V_24 ,
& V_6 -> V_18 -> V_44 ) ;
else if ( V_4 -> V_14 . V_37 == V_39 ) {
T_1 V_45 ;
if ( V_41 >= 16 )
return - V_11 ;
V_45 = ( V_21 << V_4 -> V_2 . V_21 . V_46 ) |
( V_23 << V_4 -> V_2 . V_23 . V_46 ) |
( V_24 << V_4 -> V_2 . V_24 . V_46 ) |
( V_25 << V_4 -> V_2 . V_25 . V_46 ) ;
( ( T_1 * ) ( V_4 -> V_47 ) ) [ V_41 ] = V_45 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_48 * V_14 = & V_4 -> V_14 ;
T_1 V_49 ;
if ( V_2 -> V_50 != 0 )
return - V_11 ;
V_49 = V_14 -> V_51 + ( V_2 -> V_52 * V_14 -> V_36 ) ;
V_49 &= ~ 3UL ;
F_3 ( V_49 ,
& V_6 -> V_18 -> V_53 ) ;
return 0 ;
}
static int F_7 ( char * V_54 ,
struct V_1 * V_55 )
{
char * V_56 ;
int V_57 = 0 ;
if ( ! V_54 || ! * V_54 )
return - 1 ;
while ( ( V_56 = F_8 ( & V_54 , L_1 ) ) != NULL ) {
if ( ! * V_56 )
continue;
switch ( V_57 ) {
case 0 :
V_55 -> V_17 = F_9 ( V_56 , NULL , 0 ) ;
V_57 ++ ;
break;
case 1 :
V_55 -> V_8 = V_55 -> V_12 = F_9 ( V_56 , NULL , 0 ) ;
V_57 ++ ;
break;
case 2 :
V_55 -> V_29 = F_9 ( V_56 , NULL , 0 ) ;
V_57 ++ ;
break;
case 3 :
V_55 -> V_32 = F_9 ( V_56 , NULL , 0 ) ;
V_57 ++ ;
break;
case 4 :
V_55 -> V_35 = F_9 ( V_56 , NULL , 0 ) ;
V_57 ++ ;
break;
case 5 :
V_55 -> V_9 = V_55 -> V_13 = F_9 ( V_56 , NULL , 0 ) ;
V_57 ++ ;
break;
case 6 :
V_55 -> V_28 = F_9 ( V_56 , NULL , 0 ) ;
V_57 ++ ;
break;
case 7 :
V_55 -> V_31 = F_9 ( V_56 , NULL , 0 ) ;
V_57 ++ ;
break;
case 8 :
V_55 -> V_34 = F_9 ( V_56 , NULL , 0 ) ;
V_57 ++ ;
break;
case 9 :
V_55 -> V_10 = F_9 ( V_56 , NULL , 0 ) ;
V_57 ++ ;
break;
default:
return - 1 ;
}
}
V_55 -> V_58 = V_59 ;
V_55 -> V_60 = V_61 ;
return 0 ;
}
static int F_10 ( struct V_62 * V_63 )
{
struct V_3 * V_4 ;
int V_64 = - V_16 ;
unsigned long V_65 ;
unsigned long V_66 = 0 ;
unsigned long V_67 = 0 ;
unsigned long V_68 = 0 ;
struct V_5 * V_6 = NULL ;
char * V_54 = NULL , * V_69 = NULL ;
V_4 = F_11 ( sizeof( struct V_5 ) , & V_63 -> V_63 ) ;
if ( ! V_4 ) {
F_12 ( & V_63 -> V_63 , L_2 ) ;
return - V_16 ;
}
if ( F_13 ( L_3 , & V_54 ) ) {
V_64 = - V_70 ;
goto V_71;
}
if ( ! V_54 || ! * V_54 )
V_54 = L_4 ;
while ( 1 ) {
char * V_56 = F_8 ( & V_54 , L_5 ) ;
if ( ! V_56 )
break;
if ( ! strncmp ( V_56 , L_6 , 6 ) ) {
if ( F_7 ( V_56 , & V_4 -> V_2 ) < 0 ) {
F_12 ( & V_63 -> V_63 , L_7 , V_56 ) ;
V_64 = - V_11 ;
goto V_71;
}
} else if ( ! strncmp ( V_56 , L_8 , 4 ) )
V_66 = F_9 ( V_56 + 5 , NULL , 16 ) ;
else if ( ! strncmp ( V_56 , L_9 , 4 ) )
V_68 = F_9 ( V_56 + 5 , NULL , 0 ) ;
else
V_69 = V_56 ;
}
V_6 = V_4 -> V_6 ;
V_4 -> V_72 = & V_73 ;
V_4 -> V_14 = V_74 ;
V_4 -> V_47 = V_6 -> V_75 ;
V_4 -> V_76 = V_77 | V_78 | V_79 ;
V_4 -> V_14 . V_15 = V_68 ;
if ( ! F_14 ( & V_63 -> V_63 , V_63 -> V_80 [ 0 ] . V_81 ,
F_15 ( & V_63 -> V_80 [ 0 ] ) , L_10 ) ) {
F_12 ( & V_63 -> V_63 , L_11 ) ;
V_64 = - V_82 ;
goto V_71;
}
V_6 -> V_18 = F_16 ( & V_63 -> V_80 [ 0 ] , 0 ,
F_15 ( & V_63 -> V_80 [ 0 ] ) ,
L_10 ) ;
if ( ! V_6 -> V_18 ) {
F_12 ( & V_63 -> V_63 , L_12 ) ;
V_64 = - V_16 ;
goto V_71;
}
V_64 = F_17 ( & V_4 -> V_83 , 256 , 0 ) ;
if ( V_64 < 0 ) {
F_12 ( & V_63 -> V_63 , L_13 ) ;
V_64 = - V_16 ;
goto V_84;
}
if ( V_69 ) {
V_64 = F_18 ( & V_4 -> V_2 , V_4 , V_69 ,
V_85 , sizeof( V_85 ) , & V_85 [ 0 ] , 8 ) ;
if ( ! V_64 || V_64 == 4 ) {
V_64 = - V_11 ;
goto V_86;
}
}
if ( ! V_68 )
V_68 = V_4 -> V_2 . V_12 * V_4 -> V_2 . V_13 * V_4 -> V_2 . V_10 / 8 ;
if ( V_66 ) {
V_67 = V_66 ;
if ( ! F_14 ( & V_63 -> V_63 , V_67 ,
V_68 , V_63 -> V_87 ) ) {
F_12 ( & V_63 -> V_63 , L_14 ) ;
V_64 = - V_16 ;
goto V_86;
}
V_65 = ( unsigned long ) F_19 ( V_67 , V_68 ) ;
if ( ! V_65 ) {
F_12 ( & V_63 -> V_63 , L_15 ) ;
V_64 = - V_16 ;
goto V_86;
}
} else {
unsigned long V_88 ;
V_65 = ( unsigned long ) F_20 ( V_89 ,
F_21 ( V_68 ) ) ;
if ( ! V_65 ) {
F_12 ( & V_63 -> V_63 ,
L_16 ,
V_68 ) ;
V_64 = - V_16 ;
goto V_86;
}
V_67 = F_22 ( & V_63 -> V_63 , ( void * ) V_65 , V_68 , V_90 ) ;
for ( V_88 = V_65 ;
V_88 < F_23 ( V_65 + V_68 ) ;
V_88 += V_91 ) {
F_24 ( F_25 ( V_88 ) ) ;
}
V_6 -> V_92 = 1 ;
}
memset ( ( unsigned long * ) V_65 , 0 , V_68 ) ;
V_4 -> V_93 = ( char V_94 * ) V_65 ;
V_4 -> V_14 . V_51 = V_67 ;
V_4 -> V_14 . V_15 = V_68 ;
F_26 ( & V_63 -> V_63 , V_4 ) ;
F_27 ( & V_63 -> V_63 ,
L_17 ,
V_4 -> V_95 , V_4 -> V_2 . V_8 , V_4 -> V_2 . V_9 , V_4 -> V_2 . V_10 ,
V_68 >> 10 , V_4 -> V_93 ) ;
V_64 = F_28 ( V_4 ) ;
if ( V_64 < 0 ) {
F_12 ( & V_63 -> V_63 , L_18 ) ;
goto V_96;
}
F_3 ( V_67 , & V_6 -> V_18 -> V_53 ) ;
F_3 ( F_29 ( & V_6 -> V_18 -> V_40 ) | 1 ,
& V_6 -> V_18 -> V_40 ) ;
return 0 ;
V_96:
if ( V_66 )
F_30 ( ( void * ) V_65 ) ;
else
F_31 ( ( void * ) V_65 ) ;
V_86:
F_32 ( & V_4 -> V_83 ) ;
V_84:
F_33 ( & V_63 -> V_80 [ 0 ] , V_6 -> V_18 ,
F_15 ( & V_63 -> V_80 [ 0 ] ) ) ;
V_71:
F_34 ( V_4 ) ;
return V_64 ;
}
static int F_35 ( struct V_62 * V_97 )
{
struct V_3 * V_4 = F_36 ( & V_97 -> V_63 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_4 ) {
F_37 ( V_4 ) ;
F_32 ( & V_4 -> V_83 ) ;
F_33 ( & V_97 -> V_80 [ 0 ] , V_6 -> V_18 ,
F_15 ( & V_97 -> V_80 [ 0 ] ) ) ;
if ( ! V_6 -> V_92 )
F_30 ( V_4 -> V_93 ) ;
else
F_31 ( ( void * ) V_4 -> V_93 ) ;
F_34 ( V_4 ) ;
}
return 0 ;
}
