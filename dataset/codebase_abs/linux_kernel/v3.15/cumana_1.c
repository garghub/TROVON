void F_1 ( char * V_1 , int * V_2 )
{
}
const char * F_2 ( struct V_3 * V_4 )
{
return L_1 ;
}
static inline int
F_3 ( struct V_3 * V_5 , unsigned char * V_6 , int V_7 )
{
unsigned long * V_8 ;
void T_1 * V_9 = F_4 ( V_5 ) -> V_9 + 0x2000 ;
if( ! V_7 ) return 0 ;
F_5 ( 0x02 , F_4 ( V_5 ) -> V_10 + V_11 ) ;
V_8 = ( unsigned long * ) V_6 ;
while( V_7 >= 32 )
{
unsigned int V_12 ;
unsigned long V_13 ;
V_12 = F_6 ( F_4 ( V_5 ) -> V_10 + V_14 ) ;
if( V_12 & 0x80 )
goto V_15;
if( ! ( V_12 & 0x40 ) )
continue;
V_13 = * V_8 ++ ; F_7 ( F_8 ( V_13 ) , V_9 ) ; F_7 ( F_9 ( V_13 ) , V_9 ) ;
V_13 = * V_8 ++ ; F_7 ( F_8 ( V_13 ) , V_9 ) ; F_7 ( F_9 ( V_13 ) , V_9 ) ;
V_13 = * V_8 ++ ; F_7 ( F_8 ( V_13 ) , V_9 ) ; F_7 ( F_9 ( V_13 ) , V_9 ) ;
V_13 = * V_8 ++ ; F_7 ( F_8 ( V_13 ) , V_9 ) ; F_7 ( F_9 ( V_13 ) , V_9 ) ;
V_13 = * V_8 ++ ; F_7 ( F_8 ( V_13 ) , V_9 ) ; F_7 ( F_9 ( V_13 ) , V_9 ) ;
V_13 = * V_8 ++ ; F_7 ( F_8 ( V_13 ) , V_9 ) ; F_7 ( F_9 ( V_13 ) , V_9 ) ;
V_13 = * V_8 ++ ; F_7 ( F_8 ( V_13 ) , V_9 ) ; F_7 ( F_9 ( V_13 ) , V_9 ) ;
V_13 = * V_8 ++ ; F_7 ( F_8 ( V_13 ) , V_9 ) ; F_7 ( F_9 ( V_13 ) , V_9 ) ;
V_7 -= 32 ;
if( V_7 == 0 )
break;
}
V_6 = ( unsigned char * ) V_8 ;
F_5 ( 0x12 , F_4 ( V_5 ) -> V_10 + V_11 ) ;
while( V_7 > 0 )
{
unsigned int V_12 ;
V_12 = F_6 ( F_4 ( V_5 ) -> V_10 + V_14 ) ;
if( V_12 & 0x80 )
goto V_15;
if( V_12 & 0x40 )
{
F_5 ( * V_6 ++ , V_9 ) ;
if( -- V_7 == 0 )
break;
}
V_12 = F_6 ( F_4 ( V_5 ) -> V_10 + V_14 ) ;
if( V_12 & 0x80 )
goto V_15;
if( V_12 & 0x40 )
{
F_5 ( * V_6 ++ , V_9 ) ;
if( -- V_7 == 0 )
break;
}
}
V_15:
F_5 ( F_4 ( V_5 ) -> V_16 | 0x40 , F_4 ( V_5 ) -> V_10 + V_11 ) ;
return V_7 ;
}
static inline int
F_10 ( struct V_3 * V_5 , unsigned char * V_6 , int V_7 )
{
unsigned long * V_8 ;
void T_1 * V_9 = F_4 ( V_5 ) -> V_9 + 0x2000 ;
if( ! V_7 ) return 0 ;
F_5 ( 0x00 , F_4 ( V_5 ) -> V_10 + V_11 ) ;
V_8 = ( unsigned long * ) V_6 ;
while( V_7 >= 32 )
{
unsigned int V_12 ;
V_12 = F_6 ( F_4 ( V_5 ) -> V_10 + V_14 ) ;
if( V_12 & 0x80 )
goto V_15;
if( ! ( V_12 & 0x40 ) )
continue;
* V_8 ++ = F_11 ( V_9 ) | ( F_11 ( V_9 ) << 16 ) ;
* V_8 ++ = F_11 ( V_9 ) | ( F_11 ( V_9 ) << 16 ) ;
* V_8 ++ = F_11 ( V_9 ) | ( F_11 ( V_9 ) << 16 ) ;
* V_8 ++ = F_11 ( V_9 ) | ( F_11 ( V_9 ) << 16 ) ;
* V_8 ++ = F_11 ( V_9 ) | ( F_11 ( V_9 ) << 16 ) ;
* V_8 ++ = F_11 ( V_9 ) | ( F_11 ( V_9 ) << 16 ) ;
* V_8 ++ = F_11 ( V_9 ) | ( F_11 ( V_9 ) << 16 ) ;
* V_8 ++ = F_11 ( V_9 ) | ( F_11 ( V_9 ) << 16 ) ;
V_7 -= 32 ;
if( V_7 == 0 )
break;
}
V_6 = ( unsigned char * ) V_8 ;
F_5 ( 0x10 , F_4 ( V_5 ) -> V_10 + V_11 ) ;
while( V_7 > 0 )
{
unsigned int V_12 ;
V_12 = F_6 ( F_4 ( V_5 ) -> V_10 + V_14 ) ;
if( V_12 & 0x80 )
goto V_15;
if( V_12 & 0x40 )
{
* V_6 ++ = F_6 ( V_9 ) ;
if( -- V_7 == 0 )
break;
}
V_12 = F_6 ( F_4 ( V_5 ) -> V_10 + V_14 ) ;
if( V_12 & 0x80 )
goto V_15;
if( V_12 & 0x40 )
{
* V_6 ++ = F_6 ( V_9 ) ;
if( -- V_7 == 0 )
break;
}
}
V_15:
F_5 ( F_4 ( V_5 ) -> V_16 | 0x40 , F_4 ( V_5 ) -> V_10 + V_11 ) ;
return V_7 ;
}
static unsigned char F_12 ( struct V_3 * V_5 , unsigned int V_17 )
{
void T_1 * V_10 = F_4 ( V_5 ) -> V_10 ;
unsigned char V_18 ;
F_5 ( 0 , V_10 + V_11 ) ;
V_18 = F_6 ( V_10 + 0x2100 + ( V_17 << 2 ) ) ;
F_4 ( V_5 ) -> V_16 = 0x40 ;
F_5 ( 0x40 , V_10 + V_11 ) ;
return V_18 ;
}
static void F_13 ( struct V_3 * V_5 , unsigned int V_17 , unsigned int V_19 )
{
void T_1 * V_10 = F_4 ( V_5 ) -> V_10 ;
F_5 ( 0 , V_10 + V_11 ) ;
F_5 ( V_19 , V_10 + 0x2100 + ( V_17 << 2 ) ) ;
F_4 ( V_5 ) -> V_16 = 0x40 ;
F_5 ( 0x40 , V_10 + V_11 ) ;
}
static int F_14 ( struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
struct V_3 * V_5 ;
int V_24 ;
V_24 = F_15 ( V_21 ) ;
if ( V_24 )
goto V_25;
V_5 = F_16 ( & V_26 , sizeof( struct V_27 ) ) ;
if ( ! V_5 ) {
V_24 = - V_28 ;
goto V_29;
}
F_4 ( V_5 ) -> V_10 = F_17 ( F_18 ( V_21 , V_30 ) ,
F_19 ( V_21 , V_30 ) ) ;
F_4 ( V_5 ) -> V_9 = F_17 ( F_18 ( V_21 , V_31 ) ,
F_19 ( V_21 , V_31 ) ) ;
if ( ! F_4 ( V_5 ) -> V_10 || ! F_4 ( V_5 ) -> V_9 ) {
V_24 = - V_28 ;
goto V_32;
}
V_5 -> V_33 = V_21 -> V_33 ;
F_20 ( V_5 , 0 ) ;
F_4 ( V_5 ) -> V_16 = 0 ;
F_5 ( 0 , F_4 ( V_5 ) -> V_10 + V_11 ) ;
V_5 -> V_34 = 255 ;
if ( ! ( F_21 ( V_5 -> V_35 , V_5 -> V_34 , L_2 ) ) ) {
V_24 = - V_36 ;
goto V_32;
}
V_24 = F_22 ( V_5 -> V_33 , V_37 , 0 ,
L_2 , V_5 ) ;
if ( V_24 ) {
F_23 ( L_3 ,
V_5 -> V_38 , V_5 -> V_33 , V_24 ) ;
goto V_32;
}
F_23 ( L_4 ,
V_5 -> V_38 , V_5 -> V_35 , V_5 -> V_33 ) ;
F_23 ( L_5 ,
V_5 -> V_39 , V_5 -> V_40 , V_41 ) ;
F_23 ( L_6 , V_5 -> V_38 ) ;
F_24 ( V_5 ) ;
F_23 ( L_7 ) ;
V_24 = F_25 ( V_5 , & V_21 -> V_42 ) ;
if ( V_24 )
goto V_43;
F_26 ( V_5 ) ;
goto V_25;
V_43:
F_27 ( V_5 -> V_33 , V_5 ) ;
V_32:
F_28 ( F_4 ( V_5 ) -> V_10 ) ;
F_28 ( F_4 ( V_5 ) -> V_9 ) ;
F_29 ( V_5 ) ;
V_29:
F_30 ( V_21 ) ;
V_25:
return V_24 ;
}
static void F_31 ( struct V_20 * V_21 )
{
struct V_3 * V_5 = F_32 ( V_21 ) ;
F_33 ( V_21 , NULL ) ;
F_34 ( V_5 ) ;
F_27 ( V_5 -> V_33 , V_5 ) ;
F_35 ( V_5 ) ;
F_28 ( F_4 ( V_5 ) -> V_10 ) ;
F_28 ( F_4 ( V_5 ) -> V_9 ) ;
F_29 ( V_5 ) ;
F_30 ( V_21 ) ;
}
static int T_2 F_36 ( void )
{
return F_37 ( & V_44 ) ;
}
static void T_3 F_38 ( void )
{
F_39 ( & V_44 ) ;
}
