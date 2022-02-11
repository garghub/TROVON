static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
F_2 ( & V_6 ) ;
F_2 ( & ( V_4 -> V_7 ) ) ;
if ( V_4 -> V_8 || ! V_4 -> V_9 ) {
F_3 ( & ( V_4 -> V_7 ) ) ;
F_3 ( & V_6 ) ;
return - V_10 ;
}
V_4 -> V_8 = 1 ;
F_4 ( & V_4 -> V_11 ) ;
F_3 ( & ( V_4 -> V_7 ) ) ;
F_5 ( & V_4 -> V_12 -> V_13 , L_1 ) ;
F_3 ( & V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
V_4 -> V_8 = 0 ;
F_5 ( & V_4 -> V_12 -> V_13 , L_2 ) ;
return 0 ;
}
static long F_7 ( struct V_2 * V_2 , unsigned int V_14 , unsigned long V_15 )
{
struct V_16 V_17 ;
struct V_3 * V_4 = & V_5 ;
void T_1 * V_18 ;
unsigned char * V_19 ;
int V_20 , V_21 ;
int V_22 ;
int V_23 = 0 ;
F_2 ( & ( V_4 -> V_7 ) ) ;
if ( V_4 -> V_9 == 0 || V_4 -> V_12 == NULL ) {
V_23 = - V_24 ;
goto V_25;
}
switch ( V_14 ) {
case V_26 :
V_18 = ( void T_1 * ) V_15 ;
if ( V_18 == NULL )
break;
if ( F_8 ( & V_17 , V_18 , sizeof( struct V_16 ) ) ) {
V_23 = - V_27 ;
goto V_25;
}
if ( V_17 . V_28 < 0 || V_17 . V_28 > V_29 ) {
V_23 = - V_30 ;
goto V_25;
}
V_19 = ( unsigned char * ) F_9 ( V_31 ) ;
if ( V_19 == NULL ) {
V_23 = - V_32 ;
goto V_25;
}
if ( F_8 ( V_19 , V_17 . V_19 , V_17 . V_28 ) ) {
V_23 = - V_27 ;
F_10 ( ( unsigned long ) V_19 ) ;
goto V_25;
}
V_21 = V_17 . V_21 | V_33 |
V_34 | V_35 ;
F_11
( L_3 ,
V_21 , V_17 . V_36 , V_17 . V_37 ,
V_17 . V_38 , V_17 . V_28 ) ;
V_22 = 3 ;
while ( V_22 ) {
V_20 = F_12 ( V_4 -> V_12 ,
F_13 ( V_4 -> V_12 , 0 ) ,
V_17 . V_36 ,
V_21 ,
V_17 . V_37 ,
V_17 . V_38 , V_19 ,
V_17 . V_28 ,
F_14 ( V_17 . V_39 ) ) ;
if ( V_20 == - V_40 )
V_22 -- ;
else if ( V_20 < 0 ) {
F_15 ( L_4 , V_20 ) ;
V_22 = 0 ;
} else {
F_11 ( L_5 ,
V_20 , V_19 [ 0 ] ) ;
if ( F_16 ( V_17 . V_19 , V_19 ,
V_17 . V_28 ) ) {
F_10 ( ( unsigned long ) V_19 ) ;
V_23 = - V_27 ;
goto V_25;
}
V_22 = 0 ;
}
}
F_10 ( ( unsigned long ) V_19 ) ;
break;
case V_41 :
V_18 = ( void T_1 * ) V_15 ;
if ( V_18 == NULL )
break;
if ( F_8 ( & V_17 , V_18 , sizeof( struct V_16 ) ) ) {
V_23 = - V_27 ;
goto V_25;
}
if ( V_17 . V_28 < 0 || V_17 . V_28 > V_29 ) {
V_23 = - V_30 ;
goto V_25;
}
V_19 = ( unsigned char * ) F_9 ( V_31 ) ;
if ( V_19 == NULL ) {
V_23 = - V_32 ;
goto V_25;
}
if ( F_8 ( V_19 , V_17 . V_19 , V_17 . V_28 ) ) {
F_10 ( ( unsigned long ) V_19 ) ;
V_23 = - V_27 ;
goto V_25;
}
V_21 = V_17 . V_21 | V_42 |
V_34 | V_35 ;
F_11 ( L_6 ,
V_21 , V_17 . V_36 , V_17 . V_37 ,
V_17 . V_38 , V_17 . V_28 ) ;
V_22 = 3 ;
while ( V_22 ) {
V_20 = F_12 ( V_4 -> V_12 ,
F_17 ( V_4 -> V_12 , 0 ) ,
V_17 . V_36 ,
V_21 ,
V_17 . V_37 ,
V_17 . V_38 , V_19 ,
V_17 . V_28 ,
F_14 ( V_17 . V_39 ) ) ;
if ( V_20 == - V_40 )
V_22 -- ;
else if ( V_20 < 0 ) {
F_15 ( L_4 , V_20 ) ;
V_22 = 0 ;
} else {
F_11 ( L_7 , V_20 ) ;
V_22 = 0 ;
}
}
F_10 ( ( unsigned long ) V_19 ) ;
break;
default:
V_23 = - V_43 ;
break;
}
V_25:
F_3 ( & ( V_4 -> V_7 ) ) ;
return V_23 ;
}
static T_2
F_18 ( struct V_2 * V_2 , const char T_1 * V_19 ,
T_3 V_44 , T_4 * V_45 )
{
F_19 ( V_46 ) ;
struct V_3 * V_4 = & V_5 ;
unsigned long V_47 ;
unsigned long V_48 = 0 ;
unsigned int V_49 ;
int V_20 = 0 ;
int V_50 ;
int V_51 = 0 ;
int V_52 ;
V_52 = F_20 ( & ( V_4 -> V_7 ) ) ;
if ( V_52 )
return - V_53 ;
if ( V_4 -> V_9 == 0 || V_4 -> V_12 == NULL ) {
F_3 ( & ( V_4 -> V_7 ) ) ;
return - V_24 ;
}
do {
unsigned long V_54 ;
char * V_55 = V_4 -> V_55 ;
V_54 = V_47 =
( V_44 >= V_56 ) ? V_56 : V_44 ;
if ( F_8 ( V_4 -> V_55 , V_19 , V_47 ) ) {
V_51 = - V_27 ;
goto error;
}
V_50 = 5 ;
while ( V_54 ) {
if ( ! V_4 -> V_12 ) {
V_51 = - V_24 ;
goto error;
}
if ( F_21 ( V_57 ) ) {
F_3 ( & ( V_4 -> V_7 ) ) ;
return V_48 ? V_48 : - V_53 ;
}
V_20 = F_22 ( V_4 -> V_12 ,
F_23 ( V_4 -> V_12 , 2 ) ,
V_55 , V_54 , & V_49 , 5000 ) ;
F_11 ( L_8 ,
V_20 , V_54 , V_49 ) ;
if ( V_20 == - V_40 ) {
if ( ! V_50 -- ) {
V_51 = - V_58 ;
goto error;
}
F_24 ( & V_4 -> V_11 , & V_46 , V_59 ) ;
F_25 ( V_60 ) ;
F_26 ( & V_4 -> V_11 , & V_46 ) ;
continue;
} else if ( ! V_20 && V_49 ) {
V_55 += V_49 ;
V_54 -= V_49 ;
} else
break;
} ;
if ( V_20 ) {
F_15 ( L_9 , V_20 ) ;
V_51 = - V_61 ;
goto error;
}
V_48 += V_47 ;
V_44 -= V_47 ;
V_19 += V_47 ;
} while ( V_44 > 0 );
F_3 ( & ( V_4 -> V_7 ) ) ;
return V_48 ? V_48 : - V_61 ;
error:
F_3 ( & ( V_4 -> V_7 ) ) ;
return V_51 ;
}
static T_2
F_27 ( struct V_2 * V_2 , char T_1 * V_19 , T_3 V_44 , T_4 * V_45 )
{
F_19 ( V_46 ) ;
struct V_3 * V_4 = & V_5 ;
T_2 V_62 ;
unsigned int V_49 ;
int V_63 ;
int V_20 ;
int V_50 = 10 ;
char * V_64 ;
int V_52 ;
V_52 = F_20 ( & ( V_4 -> V_7 ) ) ;
if ( V_52 )
return - V_53 ;
if ( V_4 -> V_9 == 0 || V_4 -> V_12 == NULL ) {
F_3 ( & ( V_4 -> V_7 ) ) ;
return - V_24 ;
}
V_64 = V_4 -> V_64 ;
V_62 = 0 ;
while ( V_44 > 0 ) {
if ( F_21 ( V_57 ) ) {
F_3 ( & ( V_4 -> V_7 ) ) ;
return V_62 ? V_62 : - V_53 ;
}
if ( ! V_4 -> V_12 ) {
F_3 ( & ( V_4 -> V_7 ) ) ;
return - V_24 ;
}
V_63 = ( V_44 >= V_65 ) ? V_65 : V_44 ;
V_20 = F_22 ( V_4 -> V_12 ,
F_28 ( V_4 -> V_12 , 1 ) ,
V_64 , V_63 , & V_49 ,
8000 ) ;
F_11 ( L_10 ,
V_20 , V_63 , V_49 ) ;
if ( V_49 ) {
V_44 = V_63 = V_49 ;
} else if ( V_20 == - V_40 || V_20 == 15 ) {
if ( ! V_50 -- ) {
F_3 ( & ( V_4 -> V_7 ) ) ;
F_15 ( L_11 ) ;
return - V_58 ;
}
F_24 ( & V_4 -> V_11 , & V_46 , V_59 ) ;
F_25 ( V_60 ) ;
F_26 ( & V_4 -> V_11 , & V_46 ) ;
continue;
} else if ( V_20 != - V_66 ) {
F_3 ( & ( V_4 -> V_7 ) ) ;
F_15 ( L_12 ,
V_20 , V_49 , V_63 ) ;
return - V_61 ;
} else {
F_3 ( & ( V_4 -> V_7 ) ) ;
return ( 0 ) ;
}
if ( V_63 ) {
if ( F_16 ( V_19 , V_64 , V_63 ) ) {
F_3 ( & ( V_4 -> V_7 ) ) ;
return - V_27 ;
}
V_44 -= V_63 ;
V_62 += V_63 ;
V_19 += V_63 ;
}
}
F_3 ( & ( V_4 -> V_7 ) ) ;
return V_62 ;
}
static int F_29 ( struct V_67 * V_68 ,
const struct V_69 * V_70 )
{
struct V_71 * V_13 = F_30 ( V_68 ) ;
struct V_3 * V_4 = & V_5 ;
int V_23 ;
F_5 ( & V_68 -> V_13 , L_13 , V_13 -> V_72 ) ;
V_23 = F_31 ( V_68 , & V_73 ) ;
if ( V_23 ) {
F_15 ( L_14 ) ;
return - V_32 ;
}
V_4 -> V_12 = V_13 ;
if ( ! ( V_4 -> V_55 = F_32 ( V_56 , V_31 ) ) ) {
F_15 ( L_15 ) ;
F_33 ( V_68 , & V_73 ) ;
return - V_32 ;
}
F_11 ( L_16 , V_4 -> V_55 ) ;
if ( ! ( V_4 -> V_64 = F_32 ( V_65 , V_31 ) ) ) {
F_15 ( L_17 ) ;
F_33 ( V_68 , & V_73 ) ;
F_34 ( V_4 -> V_55 ) ;
return - V_32 ;
}
F_11 ( L_18 , V_4 -> V_64 ) ;
F_35 ( & ( V_4 -> V_7 ) ) ;
F_36 ( V_68 , V_4 ) ;
V_4 -> V_9 = 1 ;
return 0 ;
}
static void F_37 ( struct V_67 * V_68 )
{
struct V_3 * V_4 = F_38 ( V_68 ) ;
F_36 ( V_68 , NULL ) ;
F_2 ( & V_6 ) ;
if ( V_4 ) {
F_33 ( V_68 , & V_73 ) ;
F_2 ( & ( V_4 -> V_7 ) ) ;
if ( V_4 -> V_8 ) {
V_4 -> V_8 = 0 ;
V_4 -> V_12 = NULL ;
F_3 ( & ( V_4 -> V_7 ) ) ;
F_3 ( & V_6 ) ;
return;
}
F_34 ( V_4 -> V_64 ) ;
F_34 ( V_4 -> V_55 ) ;
F_5 ( & V_68 -> V_13 , L_19 ) ;
V_4 -> V_9 = 0 ;
F_3 ( & ( V_4 -> V_7 ) ) ;
}
F_3 ( & V_6 ) ;
}
