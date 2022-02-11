static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
#if V_4 == 64
V_3 = * ( ( V_5 * ) & V_2 -> V_6 [ 0 ] ) ;
F_2 ( V_3 , V_2 -> V_7 ) ;
#elif V_4 == 32
V_3 = * ( ( V_8 * ) & V_2 -> V_6 [ 0 ] ) ;
F_3 ( V_3 , V_2 -> V_7 ) ;
V_3 = * ( ( V_8 * ) & V_2 -> V_6 [ 4 ] ) ;
F_3 ( V_3 , V_2 -> V_7 + 4 ) ;
#else
# error Not 32 or 64 bit
#endif
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
int V_10 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_11 -> V_12 ; V_9 ++ ) {
V_10 = F_5 ( V_2 -> V_13 ,
V_2 -> V_14 + ( V_9 * 8 ) , V_2 -> V_6 [ V_9 ] ) ;
if ( V_10 )
break;
}
if ( F_6 ( V_10 ) )
F_7 ( L_1 , V_10 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
int V_10 ;
do {
V_10 = F_9 ( V_2 -> V_13 ,
V_2 -> V_14 + V_16 ,
& V_15 ) ;
if ( V_10 )
return V_10 ;
} while ( V_15 & V_17 );
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
unsigned int V_18 ;
int V_10 ;
V_10 = F_8 ( V_2 ) ;
if ( V_10 )
return V_10 ;
do {
V_10 = F_9 ( V_2 -> V_13 ,
V_2 -> V_14 + V_19 ,
& V_18 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_8 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_9 ( V_2 -> V_13 ,
V_2 -> V_14 + V_20 ,
& V_18 ) ;
if ( V_10 )
return V_10 ;
} while ( V_18 & V_21 );
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
int V_10 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_11 -> V_12 ; V_9 ++ ) {
V_10 = F_10 ( V_2 ) ;
if ( V_10 )
break;
V_10 = F_5 ( V_2 -> V_13 ,
V_2 -> V_14 + V_19 ,
V_22 | V_9 ) ;
if ( V_10 )
break;
V_10 = F_10 ( V_2 ) ;
if ( V_10 )
break;
V_10 = F_5 ( V_2 -> V_13 ,
V_2 -> V_14 + V_23 ,
V_2 -> V_6 [ V_9 ] ) ;
if ( V_10 )
break;
}
if ( F_6 ( V_10 ) )
F_7 ( L_1 , V_10 ) ;
}
static void F_12 ( unsigned long V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
unsigned int V_9 , V_25 = V_2 -> V_26 ;
unsigned int V_12 = V_2 -> V_11 -> V_12 ;
for ( V_9 = 0 ; V_9 < V_12 ; ) {
for (; V_9 < V_12 && V_25 < V_2 -> V_27 ; V_9 ++ , V_25 ++ )
V_2 -> V_6 [ V_9 ] = V_2 -> V_28 [ V_25 ] ;
V_25 = 0 ;
}
V_2 -> V_11 -> V_29 ( V_2 ) ;
V_2 -> V_26 ++ ;
V_2 -> V_26 %= V_2 -> V_27 ;
if ( V_2 -> V_27 > V_2 -> V_11 -> V_12 )
F_13 ( & V_2 -> V_30 , V_31 + V_2 -> V_32 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
const char * V_33 , T_2 V_34 )
{
char * V_35 ;
F_15 ( & V_2 -> V_30 ) ;
if ( V_34 == - 1 )
V_34 = strlen ( V_33 ) ;
if ( V_33 [ V_34 - 1 ] == '\n' )
V_34 -- ;
V_35 = F_16 ( & V_2 -> V_36 -> V_37 , V_34 + 1 , V_38 ) ;
if ( ! V_35 )
return - V_39 ;
memcpy ( V_35 , V_33 , V_34 ) ;
V_35 [ V_34 ] = 0 ;
if ( V_2 -> V_28 )
F_17 ( & V_2 -> V_36 -> V_37 , V_2 -> V_28 ) ;
V_2 -> V_28 = V_35 ;
V_2 -> V_27 = V_34 ;
V_2 -> V_26 = 0 ;
F_12 ( ( unsigned long ) V_2 ) ;
return 0 ;
}
static T_2 F_18 ( struct V_40 * V_37 , struct V_41 * V_42 ,
char * V_43 )
{
struct V_1 * V_2 = F_19 ( V_37 ) ;
return sprintf ( V_43 , L_2 , V_2 -> V_28 ) ;
}
static T_2 F_20 ( struct V_40 * V_37 , struct V_41 * V_42 ,
const char * V_43 , T_3 V_34 )
{
struct V_1 * V_2 = F_19 ( V_37 ) ;
int V_10 ;
V_10 = F_14 ( V_2 , V_43 , V_34 ) ;
return V_10 ? : V_34 ;
}
static int F_21 ( struct V_44 * V_36 )
{
const struct V_45 * V_46 ;
const struct V_47 * V_11 ;
struct V_1 * V_2 ;
struct V_48 * V_49 ;
int V_10 ;
V_46 = F_22 ( V_50 , & V_36 -> V_37 ) ;
if ( ! V_46 )
return - V_51 ;
V_11 = V_46 -> V_52 ;
V_2 = F_23 ( & V_36 -> V_37 , sizeof( * V_2 ) + V_11 -> V_12 ,
V_38 ) ;
if ( ! V_2 )
return - V_39 ;
if ( V_11 -> V_53 ) {
V_2 -> V_13 = F_24 ( V_36 -> V_37 . V_54 -> V_55 ) ;
if ( F_25 ( V_2 -> V_13 ) )
return F_26 ( V_2 -> V_13 ) ;
if ( F_27 ( V_36 -> V_37 . V_55 , L_3 ,
& V_2 -> V_14 ) )
return - V_56 ;
} else {
V_49 = F_28 ( V_36 , V_57 , 0 ) ;
V_2 -> V_7 = F_29 ( & V_36 -> V_37 , V_49 ) ;
if ( F_25 ( V_2 -> V_7 ) )
return F_26 ( V_2 -> V_7 ) ;
}
V_2 -> V_36 = V_36 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_28 = NULL ;
V_2 -> V_26 = 0 ;
V_2 -> V_32 = V_58 / 2 ;
F_30 ( & V_2 -> V_30 ) ;
V_2 -> V_30 . V_59 = F_12 ;
V_2 -> V_30 . V_52 = ( unsigned long ) V_2 ;
F_31 ( V_36 , V_2 ) ;
V_10 = F_14 ( V_2 , L_4 V_60 L_5 , - 1 ) ;
if ( V_10 )
goto V_61;
V_10 = F_32 ( & V_36 -> V_37 , & V_62 ) ;
if ( V_10 )
goto V_61;
return 0 ;
V_61:
F_15 ( & V_2 -> V_30 ) ;
return V_10 ;
}
static int F_33 ( struct V_44 * V_36 )
{
struct V_1 * V_2 = F_34 ( V_36 ) ;
F_35 ( & V_36 -> V_37 , & V_62 ) ;
F_15 ( & V_2 -> V_30 ) ;
return 0 ;
}
