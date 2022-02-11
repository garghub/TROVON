void
F_1 ( void )
{
F_2 () ;
F_3 ( V_1 / 6 ) ;
F_4 ( V_2 ) ;
F_5 ( V_3 ) ;
F_3 ( V_1 ) ;
F_4 ( V_4 ) ;
F_3 ( V_5 ) ;
F_5 ( V_6 ) ;
F_3 ( V_7 ) ;
}
void
F_6 ( void )
{
F_2 () ;
F_5 ( V_6 ) ;
F_4 ( V_4 ) ;
F_3 ( V_7 * 2 ) ;
F_5 ( V_3 ) ;
F_3 ( V_1 * 2 ) ;
F_4 ( V_2 ) ;
F_3 ( V_8 ) ;
F_7 () ;
}
void
F_8 ( unsigned char V_9 )
{
int V_10 ;
F_2 () ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
if ( V_9 & 0x80 ) {
F_4 ( V_2 ) ;
} else {
F_4 ( V_4 ) ;
}
F_3 ( V_7 / 2 ) ;
F_5 ( V_3 ) ;
F_3 ( V_1 ) ;
F_5 ( V_6 ) ;
F_3 ( V_7 / 2 ) ;
V_9 <<= 1 ;
}
F_4 ( V_4 ) ;
F_3 ( V_7 / 2 ) ;
F_7 () ;
}
unsigned char
F_9 ( void )
{
unsigned char V_11 = 0 ;
int V_10 ;
F_10 () ;
F_7 () ;
F_3 ( V_1 / 2 ) ;
V_11 |= F_11 () ;
F_12 () ;
F_3 ( V_7 / 2 ) ;
for ( V_10 = 1 ; V_10 < 8 ; V_10 ++ ) {
V_11 <<= 1 ;
F_5 ( V_3 ) ;
F_3 ( V_1 ) ;
F_5 ( V_6 ) ;
F_3 ( V_7 ) ;
F_10 () ;
F_7 () ;
F_3 ( V_1 / 2 ) ;
V_11 |= F_11 () ;
F_12 () ;
F_3 ( V_7 / 2 ) ;
}
F_5 ( V_3 ) ;
F_3 ( V_1 ) ;
F_5 ( V_6 ) ;
return V_11 ;
}
int
F_13 ( void )
{
int V_12 = 1 ;
F_2 () ;
F_4 ( V_2 ) ;
F_7 () ;
F_3 ( V_1 / 4 ) ;
F_5 ( V_3 ) ;
#if 0
i2c_clk(1);
i2c_data(1);
i2c_data(1);
i2c_disable();
i2c_dir_in();
#endif
F_3 ( V_1 / 2 ) ;
if ( F_11 () )
V_12 = 0 ;
F_3 ( V_1 / 2 ) ;
if ( ! V_12 ) {
if ( ! F_11 () )
V_12 = 1 ;
F_3 ( V_1 / 2 ) ;
}
#if 0
i2c_data(I2C_DATA_LOW);
i2c_enable();
i2c_dir_out();
#endif
F_5 ( V_6 ) ;
F_3 ( V_1 / 4 ) ;
F_2 () ;
F_4 ( V_2 ) ;
F_3 ( V_7 / 2 ) ;
return V_12 ;
}
void
F_14 ( void )
{
F_3 ( V_7 ) ;
F_2 () ;
F_4 ( V_4 ) ;
F_3 ( V_1 / 6 ) ;
F_5 ( V_3 ) ;
F_3 ( V_1 ) ;
F_5 ( V_6 ) ;
F_3 ( V_7 / 6 ) ;
F_4 ( V_2 ) ;
F_3 ( V_7 ) ;
F_7 () ;
}
void
F_15 ( void )
{
F_3 ( V_7 ) ;
F_2 () ;
F_4 ( V_2 ) ;
F_3 ( V_1 / 6 ) ;
F_5 ( V_3 ) ;
F_3 ( V_1 ) ;
F_5 ( V_6 ) ;
F_3 ( V_7 ) ;
F_7 () ;
}
int
F_16 ( unsigned char V_13 , void * V_14 , T_1 V_15 )
{
int error , V_16 = 3 ;
unsigned char V_17 = 0 ;
unsigned char V_18 ;
unsigned long V_19 ;
F_17 ( & V_20 , V_19 ) ;
do {
error = 0 ;
F_1 () ;
F_8 ( ( V_13 & 0xfe ) ) ;
if ( ! F_13 () )
error = 1 ;
for ( V_17 = 0 ; V_17 < V_15 ; V_17 ++ ) {
memcpy ( & V_18 , V_14 + V_17 , sizeof V_18 ) ;
F_8 ( V_18 ) ;
if ( ! F_13 () )
error |= 4 ;
}
F_6 () ;
} while ( error && V_16 -- );
F_3 ( V_7 ) ;
F_18 ( & V_20 , V_19 ) ;
return - error ;
}
int
F_19 ( unsigned char V_13 , void * V_14 , T_1 V_15 )
{
unsigned char V_21 = 0 ;
unsigned char V_22 = 0 ;
int error , V_16 = 3 ;
unsigned long V_19 ;
F_17 ( & V_20 , V_19 ) ;
do {
error = 0 ;
memset ( V_14 , 0 , V_15 ) ;
F_1 () ;
F_8 ( ( V_13 | 0x01 ) ) ;
if ( ! F_13 () )
error = 1 ;
for ( V_22 = 0 ; V_22 < V_15 ; V_22 ++ ) {
V_21 = F_9 () ;
memcpy ( V_14 + V_22 , & V_21 , sizeof V_21 ) ;
if ( V_22 < ( V_15 - 1 ) )
F_14 () ;
}
F_15 () ;
F_6 () ;
} while ( error && V_16 -- );
F_18 ( & V_20 , V_19 ) ;
return - error ;
}
int
F_20 ( unsigned char V_13 , unsigned char V_23 ,
unsigned char V_24 )
{
int error , V_16 = 3 ;
unsigned long V_19 ;
F_17 ( & V_20 , V_19 ) ;
do {
error = 0 ;
F_1 () ;
F_8 ( ( V_13 & 0xfe ) ) ;
if( ! F_13 () )
error = 1 ;
F_2 () ;
F_8 ( V_23 ) ;
if( ! F_13 () )
error |= 2 ;
F_8 ( V_24 ) ;
if( ! F_13 () )
error |= 4 ;
F_6 () ;
} while( error && V_16 -- );
F_3 ( V_7 ) ;
F_18 ( & V_20 , V_19 ) ;
return - error ;
}
unsigned char
F_21 ( unsigned char V_13 , unsigned char V_23 )
{
unsigned char V_21 = 0 ;
int error , V_16 = 3 ;
unsigned long V_19 ;
F_17 ( & V_20 , V_19 ) ;
do {
error = 0 ;
F_1 () ;
F_8 ( ( V_13 & 0xfe ) ) ;
if( ! F_13 () )
error = 1 ;
F_2 () ;
F_8 ( V_23 ) ;
if( ! F_13 () )
error |= 2 ;
F_3 ( V_7 ) ;
F_1 () ;
F_8 ( V_13 | 0x01 ) ;
if( ! F_13 () )
error |= 4 ;
V_21 = F_9 () ;
F_15 () ;
F_6 () ;
} while( error && V_16 -- );
F_18 ( & V_20 , V_19 ) ;
return V_21 ;
}
static int
F_22 ( struct V_25 * V_25 , struct V_26 * V_27 )
{
return 0 ;
}
static int
F_23 ( struct V_25 * V_25 , struct V_26 * V_27 )
{
return 0 ;
}
static long
F_24 ( struct V_26 * V_26 , unsigned int V_28 , unsigned long V_29 )
{
int V_30 ;
if( F_25 ( V_28 ) != V_31 ) {
return - V_32 ;
}
switch ( F_26 ( V_28 ) ) {
case V_33 :
F_27 ( F_28 ( L_1 ,
F_29 ( V_29 ) ,
F_30 ( V_29 ) ,
F_31 ( V_29 ) ) ) ;
F_32 ( & V_34 ) ;
V_30 = F_20 ( F_29 ( V_29 ) ,
F_30 ( V_29 ) ,
F_31 ( V_29 ) ) ;
F_33 ( & V_34 ) ;
return V_30 ;
case V_35 :
{
unsigned char V_36 ;
F_27 ( F_28 ( L_2 ,
F_29 ( V_29 ) ,
F_30 ( V_29 ) ) ) ;
F_32 ( & V_34 ) ;
V_36 = F_21 ( F_29 ( V_29 ) , F_30 ( V_29 ) ) ;
F_33 ( & V_34 ) ;
F_27 ( F_28 ( L_3 , V_36 ) ) ;
return V_36 ;
}
default:
return - V_37 ;
}
return 0 ;
}
static int T_2 F_34 ( void )
{
static int V_38 ;
static int V_39 = 1 ;
if ( ! V_39 )
return V_38 ;
V_39 = 0 ;
V_38 = F_35 ( & V_40 ,
V_41 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_35 ( & V_42 , V_43 ) ;
F_36 ( & V_42 , V_44 ) ;
return V_38 ;
}
static int T_2 F_37 ( void )
{
int V_38 ;
V_38 = F_34 () ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_38 ( V_45 , V_46 , & V_47 ) ;
if ( V_38 < 0 ) {
F_28 ( V_48 L_4 ) ;
return V_38 ;
}
F_28 ( V_49
L_5 ) ;
return 0 ;
}
