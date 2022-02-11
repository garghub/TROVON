static int F_1 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , int V_4 , int V_5 , T_1 * V_6 )
{
unsigned long V_7 ;
if ( V_1 || ( V_2 > 255 ) || ( V_3 > 255 ) || ( V_4 > 4095 ) ) {
* V_6 = - 1 ;
return - V_8 ;
}
F_2 ( & V_9 , V_7 ) ;
F_3 ( F_4 ( V_2 , V_3 , V_4 ) , 0xCF8 ) ;
switch ( V_5 ) {
case 1 :
* V_6 = F_5 ( 0xCFC + ( V_4 & 3 ) ) ;
break;
case 2 :
* V_6 = F_6 ( 0xCFC + ( V_4 & 2 ) ) ;
break;
case 4 :
* V_6 = F_7 ( 0xCFC ) ;
break;
}
F_8 ( & V_9 , V_7 ) ;
return 0 ;
}
static int F_9 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , int V_4 , int V_5 , T_1 V_6 )
{
unsigned long V_7 ;
if ( V_1 || ( V_2 > 255 ) || ( V_3 > 255 ) || ( V_4 > 4095 ) )
return - V_8 ;
F_2 ( & V_9 , V_7 ) ;
F_3 ( F_4 ( V_2 , V_3 , V_4 ) , 0xCF8 ) ;
switch ( V_5 ) {
case 1 :
F_10 ( ( V_10 ) V_6 , 0xCFC + ( V_4 & 3 ) ) ;
break;
case 2 :
F_11 ( ( V_11 ) V_6 , 0xCFC + ( V_4 & 2 ) ) ;
break;
case 4 :
F_3 ( ( T_1 ) V_6 , 0xCFC ) ;
break;
}
F_8 ( & V_9 , V_7 ) ;
return 0 ;
}
static int F_12 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , int V_4 , int V_5 , T_1 * V_6 )
{
unsigned long V_7 ;
int V_12 , V_13 ;
F_13 ( V_1 ) ;
if ( ( V_2 > 255 ) || ( V_3 > 255 ) || ( V_4 > 255 ) ) {
* V_6 = - 1 ;
return - V_8 ;
}
V_12 = F_14 ( V_3 ) ;
V_13 = F_15 ( V_3 ) ;
if ( V_12 & 0x10 )
return V_14 ;
F_2 ( & V_9 , V_7 ) ;
F_10 ( ( V_10 ) ( 0xF0 | ( V_13 << 1 ) ) , 0xCF8 ) ;
F_10 ( ( V_10 ) V_2 , 0xCFA ) ;
switch ( V_5 ) {
case 1 :
* V_6 = F_5 ( F_16 ( V_12 , V_4 ) ) ;
break;
case 2 :
* V_6 = F_6 ( F_16 ( V_12 , V_4 ) ) ;
break;
case 4 :
* V_6 = F_7 ( F_16 ( V_12 , V_4 ) ) ;
break;
}
F_10 ( 0 , 0xCF8 ) ;
F_8 ( & V_9 , V_7 ) ;
return 0 ;
}
static int F_17 ( unsigned int V_1 , unsigned int V_2 ,
unsigned int V_3 , int V_4 , int V_5 , T_1 V_6 )
{
unsigned long V_7 ;
int V_12 , V_13 ;
F_13 ( V_1 ) ;
if ( ( V_2 > 255 ) || ( V_3 > 255 ) || ( V_4 > 255 ) )
return - V_8 ;
V_12 = F_14 ( V_3 ) ;
V_13 = F_15 ( V_3 ) ;
if ( V_12 & 0x10 )
return V_14 ;
F_2 ( & V_9 , V_7 ) ;
F_10 ( ( V_10 ) ( 0xF0 | ( V_13 << 1 ) ) , 0xCF8 ) ;
F_10 ( ( V_10 ) V_2 , 0xCFA ) ;
switch ( V_5 ) {
case 1 :
F_10 ( ( V_10 ) V_6 , F_16 ( V_12 , V_4 ) ) ;
break;
case 2 :
F_11 ( ( V_11 ) V_6 , F_16 ( V_12 , V_4 ) ) ;
break;
case 4 :
F_3 ( ( T_1 ) V_6 , F_16 ( V_12 , V_4 ) ) ;
break;
}
F_10 ( 0 , 0xCF8 ) ;
F_8 ( & V_9 , V_7 ) ;
return 0 ;
}
static int T_2 F_18 ( const struct V_15 * V_16 )
{
T_1 V_17 = 0 ;
int V_18 , V_3 ;
if ( V_19 & V_20 )
return 1 ;
F_19 ( V_21 , & V_18 , NULL , NULL ) ;
if ( V_18 >= 2001 )
return 1 ;
for ( V_3 = 0 ; V_3 < 0x100 ; V_3 ++ ) {
if ( V_16 -> V_22 ( 0 , 0 , V_3 , V_23 , 2 , & V_17 ) )
continue;
if ( V_17 == V_24 || V_17 == V_25 )
return 1 ;
if ( V_16 -> V_22 ( 0 , 0 , V_3 , V_26 , 2 , & V_17 ) )
continue;
if ( V_17 == V_27 || V_17 == V_28 )
return 1 ;
}
F_20 ( V_29 L_1 ) ;
return 0 ;
}
static int T_2 F_21 ( void )
{
unsigned long V_7 ;
unsigned int V_30 ;
int V_31 = 0 ;
F_22 ( V_7 ) ;
F_10 ( 0x01 , 0xCFB ) ;
V_30 = F_7 ( 0xCF8 ) ;
F_3 ( 0x80000000 , 0xCF8 ) ;
if ( F_7 ( 0xCF8 ) == 0x80000000 && F_18 ( & V_32 ) ) {
V_31 = 1 ;
}
F_3 ( V_30 , 0xCF8 ) ;
F_23 ( V_7 ) ;
return V_31 ;
}
static int T_2 F_24 ( void )
{
unsigned long V_7 ;
int V_31 = 0 ;
F_22 ( V_7 ) ;
F_10 ( 0x00 , 0xCFB ) ;
F_10 ( 0x00 , 0xCF8 ) ;
F_10 ( 0x00 , 0xCFA ) ;
if ( F_5 ( 0xCF8 ) == 0x00 && F_5 ( 0xCFA ) == 0x00 &&
F_18 ( & V_33 ) ) {
V_31 = 1 ;
}
F_23 ( V_7 ) ;
return V_31 ;
}
void T_2 F_25 ( int type )
{
if ( type == 0 )
return;
F_26 ( V_34 L_2 ,
type ) ;
if ( type == 1 ) {
V_35 = & V_32 ;
if ( V_36 )
return;
if ( ! ( V_19 & V_37 ) )
return;
F_26 ( V_34 L_3
L_4 ) ;
V_36 = & V_32 ;
return;
}
V_35 = & V_33 ;
}
int T_2 F_27 ( void )
{
if ( ( V_19 & V_38 ) == 0 )
goto V_39;
if ( ! F_28 ( 0xCF8 , 8 , L_5 ) )
goto V_39;
if ( F_21 () ) {
V_35 = & V_32 ;
V_40 = true ;
return 1 ;
}
F_29 ( 0xCF8 , 8 ) ;
V_39:
if ( ( V_19 & V_41 ) == 0 )
return 0 ;
if ( ! F_28 ( 0xCF8 , 4 , L_6 ) )
return 0 ;
if ( ! F_28 ( 0xC000 , 0x1000 , L_6 ) )
goto V_42;
if ( F_24 () ) {
V_35 = & V_33 ;
V_40 = true ;
return 2 ;
}
F_29 ( 0xC000 , 0x1000 ) ;
V_42:
F_29 ( 0xCF8 , 4 ) ;
return 0 ;
}
