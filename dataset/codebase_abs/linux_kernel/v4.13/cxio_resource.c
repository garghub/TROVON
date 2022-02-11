static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 ,
T_2 V_4 , T_2 V_5 ,
T_2 V_6 ,
int V_7 )
{
T_2 V_8 , V_9 , V_10 = 0 , V_11 ;
T_2 V_12 ;
T_2 V_13 [ 16 ] ;
F_2 ( V_3 ) ;
if ( F_3 ( V_2 , V_4 * sizeof( T_2 ) , V_14 ) )
return - V_15 ;
for ( V_8 = 0 ; V_8 < V_5 + V_6 ; V_8 ++ )
F_4 ( V_2 , ( unsigned char * ) & V_10 , sizeof( T_2 ) ) ;
if ( V_7 ) {
V_9 = 0 ;
V_12 = F_5 () ;
for ( V_8 = 0 ; V_8 < V_16 ; V_8 ++ )
V_13 [ V_8 ] = V_8 + V_5 ;
for ( V_8 = V_5 + V_16 ; V_8 < V_4 - V_6 ; V_8 ++ ) {
if ( V_9 >= V_16 ) {
V_9 = 0 ;
V_12 = F_5 () ;
}
V_11 = ( V_12 >> ( V_9 * 2 ) ) & 0xF ;
F_4 ( V_2 ,
( unsigned char * ) & V_13 [ V_11 ] ,
sizeof( T_2 ) ) ;
V_13 [ V_11 ] = V_8 ;
V_9 ++ ;
}
for ( V_8 = 0 ; V_8 < V_16 ; V_8 ++ )
F_4 ( V_2 ,
( unsigned char * ) & V_13 [ V_8 ] ,
sizeof( T_2 ) ) ;
} else
for ( V_8 = V_5 ; V_8 < V_4 - V_6 ; V_8 ++ )
F_4 ( V_2 , ( unsigned char * ) & V_8 , sizeof( T_2 ) ) ;
for ( V_8 = 0 ; V_8 < V_5 + V_6 ; V_8 ++ )
if ( F_6 ( V_2 , ( unsigned char * ) & V_10 ,
sizeof( T_2 ) , V_3 ) != sizeof( T_2 ) )
break;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 , T_2 V_5 , T_2 V_6 )
{
return ( F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_6 , 0 ) ) ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 * V_3 ,
T_2 V_4 , T_2 V_5 , T_2 V_6 )
{
return ( F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_6 , 1 ) ) ;
}
static int F_9 ( struct V_17 * V_18 )
{
T_2 V_8 ;
F_2 ( & V_18 -> V_19 -> V_20 ) ;
if ( F_3 ( & V_18 -> V_19 -> V_21 , V_22 * sizeof( T_2 ) ,
V_14 ) )
return - V_15 ;
for ( V_8 = 16 ; V_8 < V_22 ; V_8 ++ )
if ( ! ( V_8 & V_18 -> V_23 ) )
F_4 ( & V_18 -> V_19 -> V_21 ,
( unsigned char * ) & V_8 , sizeof( T_2 ) ) ;
return 0 ;
}
int F_10 ( T_2 V_24 )
{
return F_7 ( & V_25 , & V_26 , V_24 , 1 ,
0 ) ;
}
void F_11 ( void )
{
F_12 ( & V_25 ) ;
}
int F_13 ( struct V_17 * V_18 ,
T_2 V_27 , T_2 V_28 ,
T_2 V_29 , T_2 V_30 , T_2 V_31 , T_2 V_32 )
{
int V_33 = 0 ;
struct V_34 * V_19 ;
V_19 = F_14 ( sizeof( * V_19 ) , V_14 ) ;
if ( ! V_19 )
return - V_15 ;
V_18 -> V_19 = V_19 ;
V_33 = F_8 ( & V_19 -> V_35 ,
& V_19 -> V_36 ,
V_27 , 1 , 0 ) ;
if ( V_33 )
goto V_37;
V_33 = F_9 ( V_18 ) ;
if ( V_33 )
goto V_38;
V_33 = F_7 ( & V_19 -> V_39 , & V_19 -> V_40 ,
V_31 , 1 , 0 ) ;
if ( V_33 )
goto V_41;
V_33 = F_7 ( & V_19 -> V_42 , & V_19 -> V_43 ,
V_32 , 1 , 0 ) ;
if ( V_33 )
goto V_44;
return 0 ;
V_44:
F_12 ( & V_19 -> V_39 ) ;
V_41:
F_12 ( & V_19 -> V_21 ) ;
V_38:
F_12 ( & V_19 -> V_35 ) ;
V_37:
return - V_15 ;
}
static T_2 F_15 ( struct V_1 * V_2 , T_1 * V_45 )
{
T_2 V_10 ;
if ( F_6 ( V_2 , ( unsigned char * ) & V_10 , sizeof( T_2 ) , V_45 ) )
return V_10 ;
else
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , T_1 * V_45 ,
T_2 V_10 )
{
F_17 (
F_18 ( V_2 , ( unsigned char * ) & V_10 , sizeof( T_2 ) , V_45 )
== 0 ) ;
}
T_2 F_19 ( struct V_34 * V_19 )
{
return F_15 ( & V_19 -> V_35 , & V_19 -> V_36 ) ;
}
void F_20 ( struct V_34 * V_19 , T_2 V_46 )
{
F_16 ( & V_19 -> V_35 , & V_19 -> V_36 , V_46 ) ;
}
T_2 F_21 ( struct V_34 * V_19 )
{
T_2 V_47 = F_15 ( & V_19 -> V_21 ,
& V_19 -> V_20 ) ;
F_22 ( L_1 , V_48 , V_47 ) ;
return V_47 ;
}
void F_23 ( struct V_34 * V_19 , T_2 V_47 )
{
F_22 ( L_1 , V_48 , V_47 ) ;
F_16 ( & V_19 -> V_21 , & V_19 -> V_20 , V_47 ) ;
}
T_2 F_24 ( struct V_34 * V_19 )
{
return F_15 ( & V_19 -> V_39 , & V_19 -> V_40 ) ;
}
void F_25 ( struct V_34 * V_19 , T_2 V_49 )
{
F_16 ( & V_19 -> V_39 , & V_19 -> V_40 , V_49 ) ;
}
T_2 F_26 ( struct V_34 * V_19 )
{
return F_15 ( & V_19 -> V_42 , & V_19 -> V_43 ) ;
}
void F_27 ( struct V_34 * V_19 , T_2 V_50 )
{
F_16 ( & V_19 -> V_42 , & V_19 -> V_43 , V_50 ) ;
}
void F_28 ( struct V_34 * V_19 )
{
F_12 ( & V_19 -> V_35 ) ;
F_12 ( & V_19 -> V_39 ) ;
F_12 ( & V_19 -> V_21 ) ;
F_12 ( & V_19 -> V_42 ) ;
F_29 ( V_19 ) ;
}
T_2 F_30 ( struct V_17 * V_18 , int V_51 )
{
unsigned long V_52 = F_31 ( V_18 -> V_53 , V_51 ) ;
F_22 ( L_2 , V_48 , ( T_2 ) V_52 , V_51 ) ;
return ( T_2 ) V_52 ;
}
void F_32 ( struct V_17 * V_18 , T_2 V_52 , int V_51 )
{
F_22 ( L_2 , V_48 , V_52 , V_51 ) ;
F_33 ( V_18 -> V_53 , ( unsigned long ) V_52 , V_51 ) ;
}
int F_34 ( struct V_17 * V_18 )
{
unsigned V_54 , V_55 ;
V_18 -> V_53 = F_35 ( V_56 , - 1 ) ;
if ( ! V_18 -> V_53 )
return - V_15 ;
V_54 = V_18 -> V_57 . V_58 ;
V_55 = V_18 -> V_57 . V_59 - V_54 + 1 ;
while ( V_54 < V_18 -> V_57 . V_59 ) {
V_55 = F_36 ( V_18 -> V_57 . V_59 - V_54 + 1 ,
V_55 ) ;
if ( F_37 ( V_18 -> V_53 , V_54 , V_55 , - 1 ) ) {
F_22 ( L_3 ,
V_48 , V_54 , V_55 ) ;
if ( V_55 <= 1024 << V_56 ) {
F_38 ( L_4 ,
V_48 , V_54 ,
V_18 -> V_57 . V_59 - V_54 ) ;
return 0 ;
}
V_55 >>= 1 ;
} else {
F_22 ( L_5 ,
V_48 , V_54 , V_55 ) ;
V_54 += V_55 ;
}
}
return 0 ;
}
void F_39 ( struct V_17 * V_18 )
{
F_40 ( V_18 -> V_53 ) ;
}
T_2 F_41 ( struct V_17 * V_18 , int V_51 )
{
unsigned long V_52 = F_31 ( V_18 -> V_60 , V_51 << 6 ) ;
F_22 ( L_2 , V_48 , ( T_2 ) V_52 , V_51 << 6 ) ;
return ( T_2 ) V_52 ;
}
void F_42 ( struct V_17 * V_18 , T_2 V_52 , int V_51 )
{
F_22 ( L_2 , V_48 , V_52 , V_51 << 6 ) ;
F_33 ( V_18 -> V_60 , ( unsigned long ) V_52 , V_51 << 6 ) ;
}
int F_43 ( struct V_17 * V_18 )
{
unsigned long V_8 ;
V_18 -> V_60 = F_35 ( V_61 , - 1 ) ;
if ( V_18 -> V_60 )
for ( V_8 = V_18 -> V_57 . V_62 ;
V_8 <= V_18 -> V_57 . V_63 - V_64 + 1 ;
V_8 += V_64 )
F_37 ( V_18 -> V_60 , V_8 , V_64 , - 1 ) ;
return V_18 -> V_60 ? 0 : - V_15 ;
}
void F_44 ( struct V_17 * V_18 )
{
F_40 ( V_18 -> V_60 ) ;
}
