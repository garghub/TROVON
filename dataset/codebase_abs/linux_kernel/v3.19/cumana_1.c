void F_1 ( char * V_1 , int * V_2 )
{
}
static inline int
F_2 ( struct V_3 * V_4 , unsigned char * V_5 , int V_6 )
{
unsigned long * V_7 ;
void T_1 * V_8 = F_3 ( V_4 ) -> V_8 + 0x2000 ;
if( ! V_6 ) return 0 ;
F_4 ( 0x02 , F_3 ( V_4 ) -> V_9 + V_10 ) ;
V_7 = ( unsigned long * ) V_5 ;
while( V_6 >= 32 )
{
unsigned int V_11 ;
unsigned long V_12 ;
V_11 = F_5 ( F_3 ( V_4 ) -> V_9 + V_13 ) ;
if( V_11 & 0x80 )
goto V_14;
if( ! ( V_11 & 0x40 ) )
continue;
V_12 = * V_7 ++ ; F_6 ( F_7 ( V_12 ) , V_8 ) ; F_6 ( F_8 ( V_12 ) , V_8 ) ;
V_12 = * V_7 ++ ; F_6 ( F_7 ( V_12 ) , V_8 ) ; F_6 ( F_8 ( V_12 ) , V_8 ) ;
V_12 = * V_7 ++ ; F_6 ( F_7 ( V_12 ) , V_8 ) ; F_6 ( F_8 ( V_12 ) , V_8 ) ;
V_12 = * V_7 ++ ; F_6 ( F_7 ( V_12 ) , V_8 ) ; F_6 ( F_8 ( V_12 ) , V_8 ) ;
V_12 = * V_7 ++ ; F_6 ( F_7 ( V_12 ) , V_8 ) ; F_6 ( F_8 ( V_12 ) , V_8 ) ;
V_12 = * V_7 ++ ; F_6 ( F_7 ( V_12 ) , V_8 ) ; F_6 ( F_8 ( V_12 ) , V_8 ) ;
V_12 = * V_7 ++ ; F_6 ( F_7 ( V_12 ) , V_8 ) ; F_6 ( F_8 ( V_12 ) , V_8 ) ;
V_12 = * V_7 ++ ; F_6 ( F_7 ( V_12 ) , V_8 ) ; F_6 ( F_8 ( V_12 ) , V_8 ) ;
V_6 -= 32 ;
if( V_6 == 0 )
break;
}
V_5 = ( unsigned char * ) V_7 ;
F_4 ( 0x12 , F_3 ( V_4 ) -> V_9 + V_10 ) ;
while( V_6 > 0 )
{
unsigned int V_11 ;
V_11 = F_5 ( F_3 ( V_4 ) -> V_9 + V_13 ) ;
if( V_11 & 0x80 )
goto V_14;
if( V_11 & 0x40 )
{
F_4 ( * V_5 ++ , V_8 ) ;
if( -- V_6 == 0 )
break;
}
V_11 = F_5 ( F_3 ( V_4 ) -> V_9 + V_13 ) ;
if( V_11 & 0x80 )
goto V_14;
if( V_11 & 0x40 )
{
F_4 ( * V_5 ++ , V_8 ) ;
if( -- V_6 == 0 )
break;
}
}
V_14:
F_4 ( F_3 ( V_4 ) -> V_15 | 0x40 , F_3 ( V_4 ) -> V_9 + V_10 ) ;
return V_6 ;
}
static inline int
F_9 ( struct V_3 * V_4 , unsigned char * V_5 , int V_6 )
{
unsigned long * V_7 ;
void T_1 * V_8 = F_3 ( V_4 ) -> V_8 + 0x2000 ;
if( ! V_6 ) return 0 ;
F_4 ( 0x00 , F_3 ( V_4 ) -> V_9 + V_10 ) ;
V_7 = ( unsigned long * ) V_5 ;
while( V_6 >= 32 )
{
unsigned int V_11 ;
V_11 = F_5 ( F_3 ( V_4 ) -> V_9 + V_13 ) ;
if( V_11 & 0x80 )
goto V_14;
if( ! ( V_11 & 0x40 ) )
continue;
* V_7 ++ = F_10 ( V_8 ) | ( F_10 ( V_8 ) << 16 ) ;
* V_7 ++ = F_10 ( V_8 ) | ( F_10 ( V_8 ) << 16 ) ;
* V_7 ++ = F_10 ( V_8 ) | ( F_10 ( V_8 ) << 16 ) ;
* V_7 ++ = F_10 ( V_8 ) | ( F_10 ( V_8 ) << 16 ) ;
* V_7 ++ = F_10 ( V_8 ) | ( F_10 ( V_8 ) << 16 ) ;
* V_7 ++ = F_10 ( V_8 ) | ( F_10 ( V_8 ) << 16 ) ;
* V_7 ++ = F_10 ( V_8 ) | ( F_10 ( V_8 ) << 16 ) ;
* V_7 ++ = F_10 ( V_8 ) | ( F_10 ( V_8 ) << 16 ) ;
V_6 -= 32 ;
if( V_6 == 0 )
break;
}
V_5 = ( unsigned char * ) V_7 ;
F_4 ( 0x10 , F_3 ( V_4 ) -> V_9 + V_10 ) ;
while( V_6 > 0 )
{
unsigned int V_11 ;
V_11 = F_5 ( F_3 ( V_4 ) -> V_9 + V_13 ) ;
if( V_11 & 0x80 )
goto V_14;
if( V_11 & 0x40 )
{
* V_5 ++ = F_5 ( V_8 ) ;
if( -- V_6 == 0 )
break;
}
V_11 = F_5 ( F_3 ( V_4 ) -> V_9 + V_13 ) ;
if( V_11 & 0x80 )
goto V_14;
if( V_11 & 0x40 )
{
* V_5 ++ = F_5 ( V_8 ) ;
if( -- V_6 == 0 )
break;
}
}
V_14:
F_4 ( F_3 ( V_4 ) -> V_15 | 0x40 , F_3 ( V_4 ) -> V_9 + V_10 ) ;
return V_6 ;
}
static unsigned char F_11 ( struct V_3 * V_4 , unsigned int V_16 )
{
void T_1 * V_9 = F_3 ( V_4 ) -> V_9 ;
unsigned char V_17 ;
F_4 ( 0 , V_9 + V_10 ) ;
V_17 = F_5 ( V_9 + 0x2100 + ( V_16 << 2 ) ) ;
F_3 ( V_4 ) -> V_15 = 0x40 ;
F_4 ( 0x40 , V_9 + V_10 ) ;
return V_17 ;
}
static void F_12 ( struct V_3 * V_4 , unsigned int V_16 , unsigned int V_18 )
{
void T_1 * V_9 = F_3 ( V_4 ) -> V_9 ;
F_4 ( 0 , V_9 + V_10 ) ;
F_4 ( V_18 , V_9 + 0x2100 + ( V_16 << 2 ) ) ;
F_3 ( V_4 ) -> V_15 = 0x40 ;
F_4 ( 0x40 , V_9 + V_10 ) ;
}
static int F_13 ( struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_3 * V_4 ;
int V_23 ;
V_23 = F_14 ( V_20 ) ;
if ( V_23 )
goto V_24;
V_4 = F_15 ( & V_25 , sizeof( struct V_26 ) ) ;
if ( ! V_4 ) {
V_23 = - V_27 ;
goto V_28;
}
F_3 ( V_4 ) -> V_9 = F_16 ( F_17 ( V_20 , V_29 ) ,
F_18 ( V_20 , V_29 ) ) ;
F_3 ( V_4 ) -> V_8 = F_16 ( F_17 ( V_20 , V_30 ) ,
F_18 ( V_20 , V_30 ) ) ;
if ( ! F_3 ( V_4 ) -> V_9 || ! F_3 ( V_4 ) -> V_8 ) {
V_23 = - V_27 ;
goto V_31;
}
V_4 -> V_32 = V_20 -> V_32 ;
F_19 ( V_4 , 0 ) ;
F_3 ( V_4 ) -> V_15 = 0 ;
F_4 ( 0 , F_3 ( V_4 ) -> V_9 + V_10 ) ;
V_4 -> V_33 = 255 ;
if ( ! ( F_20 ( V_4 -> V_34 , V_4 -> V_33 , L_1 ) ) ) {
V_23 = - V_35 ;
goto V_31;
}
V_23 = F_21 ( V_4 -> V_32 , V_36 , 0 ,
L_1 , V_4 ) ;
if ( V_23 ) {
F_22 ( L_2 ,
V_4 -> V_37 , V_4 -> V_32 , V_23 ) ;
goto V_31;
}
V_23 = F_23 ( V_4 , & V_20 -> V_38 ) ;
if ( V_23 )
goto V_39;
F_24 ( V_4 ) ;
goto V_24;
V_39:
F_25 ( V_4 -> V_32 , V_4 ) ;
V_31:
F_26 ( F_3 ( V_4 ) -> V_9 ) ;
F_26 ( F_3 ( V_4 ) -> V_8 ) ;
F_27 ( V_4 ) ;
V_28:
F_28 ( V_20 ) ;
V_24:
return V_23 ;
}
static void F_29 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_30 ( V_20 ) ;
F_31 ( V_20 , NULL ) ;
F_32 ( V_4 ) ;
F_25 ( V_4 -> V_32 , V_4 ) ;
F_33 ( V_4 ) ;
F_26 ( F_3 ( V_4 ) -> V_9 ) ;
F_26 ( F_3 ( V_4 ) -> V_8 ) ;
F_27 ( V_4 ) ;
F_28 ( V_20 ) ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_40 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_40 ) ;
}
