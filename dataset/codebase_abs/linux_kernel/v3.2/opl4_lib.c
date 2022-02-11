static void inline F_1 ( struct V_1 * V_2 )
{
int V_3 = 10 ;
while ( ( F_2 ( V_2 -> V_4 ) & V_5 ) && -- V_3 > 0 )
;
}
void F_3 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_7 )
{
F_1 ( V_2 ) ;
F_4 ( V_6 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_4 ( V_7 , V_2 -> V_8 + 1 ) ;
}
T_1 F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
F_1 ( V_2 ) ;
F_4 ( V_6 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
return F_2 ( V_2 -> V_8 + 1 ) ;
}
void F_6 ( struct V_1 * V_2 , char * V_9 , int V_10 , int V_11 )
{
unsigned long V_12 ;
T_1 V_13 ;
F_7 ( & V_2 -> V_14 , V_12 ) ;
V_13 = F_5 ( V_2 , V_15 ) ;
F_3 ( V_2 , V_15 , V_13 | V_16 ) ;
F_3 ( V_2 , V_17 , V_10 >> 16 ) ;
F_3 ( V_2 , V_18 , V_10 >> 8 ) ;
F_3 ( V_2 , V_19 , V_10 ) ;
F_1 ( V_2 ) ;
F_4 ( V_20 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_8 ( V_2 -> V_8 + 1 , V_9 , V_11 ) ;
F_3 ( V_2 , V_15 , V_13 ) ;
F_9 ( & V_2 -> V_14 , V_12 ) ;
}
void F_10 ( struct V_1 * V_2 , const char * V_9 , int V_10 , int V_11 )
{
unsigned long V_12 ;
T_1 V_13 ;
F_7 ( & V_2 -> V_14 , V_12 ) ;
V_13 = F_5 ( V_2 , V_15 ) ;
F_3 ( V_2 , V_15 , V_13 | V_16 ) ;
F_3 ( V_2 , V_17 , V_10 >> 16 ) ;
F_3 ( V_2 , V_18 , V_10 >> 8 ) ;
F_3 ( V_2 , V_19 , V_10 ) ;
F_1 ( V_2 ) ;
F_4 ( V_20 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 -> V_8 + 1 , V_9 , V_11 ) ;
F_3 ( V_2 , V_15 , V_13 ) ;
F_9 ( & V_2 -> V_14 , V_12 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_4 ( V_21 , V_2 -> V_4 + 2 ) ;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 -> V_4 ) ;
F_4 ( V_22 | V_23 , V_2 -> V_4 + 3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 -> V_4 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_1 V_24 , V_25 ;
F_12 ( V_2 ) ;
V_24 = F_5 ( V_2 , V_15 ) ;
F_14 ( L_1 , V_24 ) ;
switch ( V_24 & V_26 ) {
case 0x20 :
V_2 -> V_27 = V_28 ;
break;
case 0x40 :
V_2 -> V_27 = V_29 ;
break;
default:
return - V_30 ;
}
F_3 ( V_2 , V_31 , 0x00 ) ;
F_3 ( V_2 , V_32 , 0xff ) ;
V_24 = F_5 ( V_2 , V_31 ) ;
V_25 = F_5 ( V_2 , V_32 ) ;
F_14 ( L_2 , V_24 , V_25 ) ;
if ( V_24 != 0x00 || V_25 != 0xff )
return - V_30 ;
F_3 ( V_2 , V_31 , 0x3f ) ;
F_3 ( V_2 , V_32 , 0x3f ) ;
F_3 ( V_2 , V_15 , 0x00 ) ;
return 0 ;
}
static void F_15 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
V_2 -> V_34 = NULL ;
}
static int F_16 ( struct V_1 * V_2 , int V_36 )
{
V_2 -> V_37 = V_36 ;
if ( F_17 ( V_2 -> V_38 , V_36 , V_39 ,
sizeof( struct V_1 * ) , & V_2 -> V_34 ) >= 0 ) {
strcpy ( V_2 -> V_34 -> V_40 , L_3 ) ;
* (struct V_1 * * ) F_18 ( V_2 -> V_34 ) = V_2 ;
V_2 -> V_34 -> V_35 = V_2 ;
V_2 -> V_34 -> V_41 = F_15 ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
#ifdef F_20
F_21 ( V_2 ) ;
#endif
F_22 ( V_2 -> V_42 ) ;
F_22 ( V_2 -> V_43 ) ;
F_23 ( V_2 ) ;
}
static int F_24 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_46 ;
F_19 ( V_2 ) ;
return 0 ;
}
int F_25 ( struct V_47 * V_38 ,
unsigned long V_4 , unsigned long V_8 ,
int V_36 ,
struct V_48 * * V_49 , struct V_1 * * V_50 )
{
struct V_1 * V_2 ;
struct V_48 * V_51 ;
int V_52 ;
static struct V_53 V_54 = {
. V_55 = F_24
} ;
if ( V_49 )
* V_49 = NULL ;
if ( V_50 )
* V_50 = NULL ;
V_2 = F_26 ( sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 )
return - V_57 ;
V_2 -> V_42 = F_27 ( V_4 , 8 , L_4 ) ;
V_2 -> V_43 = F_27 ( V_8 , 8 , L_5 ) ;
if ( ! V_2 -> V_42 || ! V_2 -> V_43 ) {
F_28 ( V_58 L_6 , V_4 , V_8 ) ;
F_19 ( V_2 ) ;
return - V_59 ;
}
V_2 -> V_38 = V_38 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_8 = V_8 ;
F_29 ( & V_2 -> V_14 ) ;
F_30 ( & V_2 -> V_60 ) ;
V_52 = F_13 ( V_2 ) ;
if ( V_52 < 0 ) {
F_19 ( V_2 ) ;
F_31 ( L_7 , V_4 , V_8 ) ;
return V_52 ;
}
V_52 = F_32 ( V_38 , V_61 , V_2 , & V_54 ) ;
if ( V_52 < 0 ) {
F_19 ( V_2 ) ;
return V_52 ;
}
V_52 = F_33 ( V_38 , V_4 , V_4 + 2 , V_2 -> V_27 , 1 , & V_51 ) ;
if ( V_52 < 0 ) {
F_34 ( V_38 , V_2 ) ;
return V_52 ;
}
F_12 ( V_2 ) ;
F_35 ( V_2 ) ;
#ifdef F_20
F_36 ( V_2 ) ;
#endif
#if F_37 ( V_62 ) || ( F_37 ( V_63 ) && F_37 ( V_64 ) )
V_2 -> V_65 = - 1 ;
if ( V_2 -> V_27 < V_29 )
F_16 ( V_2 , V_36 ) ;
#endif
if ( V_49 )
* V_49 = V_51 ;
if ( V_50 )
* V_50 = V_2 ;
return 0 ;
}
static int T_2 F_38 ( void )
{
return 0 ;
}
static void T_3 F_39 ( void )
{
}
