static inline int F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 )
{
unsigned long * V_5 ;
T_1 T_2 * V_6 = V_2 -> V_7 ;
T_1 T_2 * V_8 = V_2 -> V_9 + 0x2000 ;
if( ! V_4 ) return 0 ;
F_2 ( 0x02 , V_6 + V_10 ) ;
V_5 = ( unsigned long * ) V_3 ;
while( V_4 >= 32 )
{
unsigned int V_11 ;
unsigned long V_12 ;
V_11 = F_3 ( V_6 + V_13 ) ;
if( V_11 & 0x80 )
goto V_14;
if( ! ( V_11 & 0x40 ) )
continue;
V_12 = * V_5 ++ ; F_4 ( F_5 ( V_12 ) , V_8 ) ; F_4 ( F_6 ( V_12 ) , V_8 ) ;
V_12 = * V_5 ++ ; F_4 ( F_5 ( V_12 ) , V_8 ) ; F_4 ( F_6 ( V_12 ) , V_8 ) ;
V_12 = * V_5 ++ ; F_4 ( F_5 ( V_12 ) , V_8 ) ; F_4 ( F_6 ( V_12 ) , V_8 ) ;
V_12 = * V_5 ++ ; F_4 ( F_5 ( V_12 ) , V_8 ) ; F_4 ( F_6 ( V_12 ) , V_8 ) ;
V_12 = * V_5 ++ ; F_4 ( F_5 ( V_12 ) , V_8 ) ; F_4 ( F_6 ( V_12 ) , V_8 ) ;
V_12 = * V_5 ++ ; F_4 ( F_5 ( V_12 ) , V_8 ) ; F_4 ( F_6 ( V_12 ) , V_8 ) ;
V_12 = * V_5 ++ ; F_4 ( F_5 ( V_12 ) , V_8 ) ; F_4 ( F_6 ( V_12 ) , V_8 ) ;
V_12 = * V_5 ++ ; F_4 ( F_5 ( V_12 ) , V_8 ) ; F_4 ( F_6 ( V_12 ) , V_8 ) ;
V_4 -= 32 ;
if( V_4 == 0 )
break;
}
V_3 = ( unsigned char * ) V_5 ;
F_2 ( 0x12 , V_6 + V_10 ) ;
while( V_4 > 0 )
{
unsigned int V_11 ;
V_11 = F_3 ( V_6 + V_13 ) ;
if( V_11 & 0x80 )
goto V_14;
if( V_11 & 0x40 )
{
F_2 ( * V_3 ++ , V_8 ) ;
if( -- V_4 == 0 )
break;
}
V_11 = F_3 ( V_6 + V_13 ) ;
if( V_11 & 0x80 )
goto V_14;
if( V_11 & 0x40 )
{
F_2 ( * V_3 ++ , V_8 ) ;
if( -- V_4 == 0 )
break;
}
}
V_14:
F_2 ( V_2 -> V_15 | 0x40 , V_6 + V_10 ) ;
if ( V_4 )
return - 1 ;
return 0 ;
}
static inline int F_7 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 )
{
unsigned long * V_5 ;
T_1 T_2 * V_6 = V_2 -> V_7 ;
T_1 T_2 * V_8 = V_2 -> V_9 + 0x2000 ;
if( ! V_4 ) return 0 ;
F_2 ( 0x00 , V_6 + V_10 ) ;
V_5 = ( unsigned long * ) V_3 ;
while( V_4 >= 32 )
{
unsigned int V_11 ;
V_11 = F_3 ( V_6 + V_13 ) ;
if( V_11 & 0x80 )
goto V_14;
if( ! ( V_11 & 0x40 ) )
continue;
* V_5 ++ = F_8 ( V_8 ) | ( F_8 ( V_8 ) << 16 ) ;
* V_5 ++ = F_8 ( V_8 ) | ( F_8 ( V_8 ) << 16 ) ;
* V_5 ++ = F_8 ( V_8 ) | ( F_8 ( V_8 ) << 16 ) ;
* V_5 ++ = F_8 ( V_8 ) | ( F_8 ( V_8 ) << 16 ) ;
* V_5 ++ = F_8 ( V_8 ) | ( F_8 ( V_8 ) << 16 ) ;
* V_5 ++ = F_8 ( V_8 ) | ( F_8 ( V_8 ) << 16 ) ;
* V_5 ++ = F_8 ( V_8 ) | ( F_8 ( V_8 ) << 16 ) ;
* V_5 ++ = F_8 ( V_8 ) | ( F_8 ( V_8 ) << 16 ) ;
V_4 -= 32 ;
if( V_4 == 0 )
break;
}
V_3 = ( unsigned char * ) V_5 ;
F_2 ( 0x10 , V_6 + V_10 ) ;
while( V_4 > 0 )
{
unsigned int V_11 ;
V_11 = F_3 ( V_6 + V_13 ) ;
if( V_11 & 0x80 )
goto V_14;
if( V_11 & 0x40 )
{
* V_3 ++ = F_3 ( V_8 ) ;
if( -- V_4 == 0 )
break;
}
V_11 = F_3 ( V_6 + V_13 ) ;
if( V_11 & 0x80 )
goto V_14;
if( V_11 & 0x40 )
{
* V_3 ++ = F_3 ( V_8 ) ;
if( -- V_4 == 0 )
break;
}
}
V_14:
F_2 ( V_2 -> V_15 | 0x40 , V_6 + V_10 ) ;
if ( V_4 )
return - 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
return V_17 -> V_18 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
unsigned int V_19 )
{
T_1 T_2 * V_6 = V_2 -> V_7 ;
T_1 V_20 ;
F_2 ( 0 , V_6 + V_10 ) ;
V_20 = F_3 ( V_6 + 0x2100 + ( V_19 << 2 ) ) ;
V_2 -> V_15 = 0x40 ;
F_2 ( 0x40 , V_6 + V_10 ) ;
return V_20 ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned int V_19 , T_1 V_21 )
{
T_1 T_2 * V_6 = V_2 -> V_7 ;
F_2 ( 0 , V_6 + V_10 ) ;
F_2 ( V_21 , V_6 + 0x2100 + ( V_19 << 2 ) ) ;
V_2 -> V_15 = 0x40 ;
F_2 ( 0x40 , V_6 + V_10 ) ;
}
static int F_12 ( struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_26 * V_27 ;
int V_28 ;
V_28 = F_13 ( V_23 ) ;
if ( V_28 )
goto V_29;
V_27 = F_14 ( & V_30 , sizeof( struct V_1 ) ) ;
if ( ! V_27 ) {
V_28 = - V_31 ;
goto V_32;
}
F_15 ( V_27 ) -> V_7 = F_16 ( F_17 ( V_23 , V_33 ) ,
F_18 ( V_23 , V_33 ) ) ;
F_15 ( V_27 ) -> V_9 = F_16 ( F_17 ( V_23 , V_34 ) ,
F_18 ( V_23 , V_34 ) ) ;
if ( ! F_15 ( V_27 ) -> V_7 || ! F_15 ( V_27 ) -> V_9 ) {
V_28 = - V_31 ;
goto V_35;
}
V_27 -> V_36 = V_23 -> V_36 ;
V_28 = F_19 ( V_27 , V_37 | V_38 ) ;
if ( V_28 )
goto V_35;
F_20 ( V_27 ) ;
F_15 ( V_27 ) -> V_15 = 0 ;
F_2 ( 0 , F_15 ( V_27 ) -> V_7 + V_10 ) ;
V_28 = F_21 ( V_27 -> V_36 , V_39 , 0 ,
L_1 , V_27 ) ;
if ( V_28 ) {
F_22 ( L_2 ,
V_27 -> V_40 , V_27 -> V_36 , V_28 ) ;
goto V_41;
}
V_28 = F_23 ( V_27 , & V_23 -> V_42 ) ;
if ( V_28 )
goto V_43;
F_24 ( V_27 ) ;
goto V_29;
V_43:
F_25 ( V_27 -> V_36 , V_27 ) ;
V_41:
F_26 ( V_27 ) ;
V_35:
F_27 ( F_15 ( V_27 ) -> V_7 ) ;
F_27 ( F_15 ( V_27 ) -> V_9 ) ;
F_28 ( V_27 ) ;
V_32:
F_29 ( V_23 ) ;
V_29:
return V_28 ;
}
static void F_30 ( struct V_22 * V_23 )
{
struct V_26 * V_27 = F_31 ( V_23 ) ;
void T_2 * V_6 = F_15 ( V_27 ) -> V_7 ;
void T_2 * V_8 = F_15 ( V_27 ) -> V_9 ;
F_32 ( V_23 , NULL ) ;
F_33 ( V_27 ) ;
F_25 ( V_27 -> V_36 , V_27 ) ;
F_26 ( V_27 ) ;
F_28 ( V_27 ) ;
F_27 ( V_6 ) ;
F_27 ( V_8 ) ;
F_29 ( V_23 ) ;
}
static int T_3 F_34 ( void )
{
return F_35 ( & V_44 ) ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_44 ) ;
}
