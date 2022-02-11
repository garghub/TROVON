static void F_1 ( int V_1 )
{
while ( F_2 ( V_2 ) & 1 )
;
F_3 ( V_2 , ( V_1 << 8 ) | V_3 | 1 ) ;
while ( F_2 ( V_2 ) & 1 )
;
}
static void F_4 ( int V_1 )
{
while ( F_5 ( V_2 ) & 0x10000 )
;
F_6 ( V_2 , V_1 | V_3 | 0x10000 ) ;
while ( F_5 ( V_2 ) & 0x10000 )
;
}
static void F_7 ( void )
{
F_8 ( V_4 ) ;
F_3 ( & V_5 -> V_6 , F_2 ( & V_5 -> V_6 ) & ~ 3 ) ;
}
static void F_9 ( void )
{
F_8 ( V_4 ) ;
F_6 ( & V_7 -> V_8 , F_5 ( & V_7 -> V_8 ) & ~ 0x30 ) ;
}
static void F_10 ( void )
{
F_3 ( & V_5 -> V_6 , F_2 ( & V_5 -> V_6 ) | 3 ) ;
F_8 ( V_9 ) ;
}
static void F_11 ( void )
{
F_6 ( & V_7 -> V_8 , F_5 ( & V_7 -> V_8 ) | 0x30 ) ;
F_8 ( V_9 ) ;
}
static int F_12 ( void )
{
F_13 () ;
F_14 ( & V_10 -> V_11 , 0x10 ) ;
F_14 ( & V_10 -> V_12 , 0x10 ) ;
F_3 ( & V_10 -> V_13 , 1 ) ;
F_3 ( & V_10 -> V_14 , 0 ) ;
F_3 ( & V_10 -> V_15 , 0 ) ;
F_3 ( & V_10 -> V_16 , 0 ) ;
F_3 ( & V_10 -> V_17 , 0 ) ;
V_18 = V_19 ;
V_18 -> V_20 = ( V_21 * ) V_18 - 1 ;
V_18 -> V_22 = 0xa000 ;
V_18 -> V_23 = 1 ;
V_24 = V_18 + 1 ;
V_24 -> V_20 = ( V_21 * ) V_18 - 2 ;
V_24 -> V_22 = 0x2000 ;
V_24 -> V_23 = 1 ;
F_15 () ;
F_3 ( & V_10 -> V_25 , V_26 ) ;
F_3 ( & V_10 -> V_27 , V_26 + sizeof( struct V_28 ) ) ;
F_8 ( V_29 ) ;
F_16 () ;
return 0 ;
}
static void F_17 ( unsigned char V_30 )
{
while ( V_24 -> V_22 & 0x8000 )
F_18 () ;
F_15 () ;
V_24 -> V_20 [ 0 ] = V_30 ;
F_19 () ;
V_24 -> V_22 |= 0x8000 ;
}
static unsigned char F_20 ( void )
{
F_18 () ;
return ! ( V_18 -> V_22 & 0x8000 ) ;
}
static unsigned char F_21 ( void )
{
unsigned char V_30 ;
while ( ! F_20 () )
;
F_15 () ;
V_30 = V_18 -> V_20 [ 0 ] ;
F_19 () ;
V_18 -> V_22 |= 0x8000 ;
return V_30 ;
}
int F_22 ( void * V_31 , struct V_32 * V_33 )
{
void * V_34 [ 2 ] ;
T_1 V_35 [ 2 ] ;
int V_36 = 0 , V_37 = 0 ;
void * V_38 , * V_39 ;
void * V_40 ;
unsigned long V_41 , V_42 ;
if ( F_23 ( V_31 , L_1 ) ) {
V_36 = 1 ;
} else if ( F_23 ( V_31 , L_2 ) ) {
V_37 = 1 ;
} else if ( F_23 ( V_31 , L_3 ) ) {
V_37 = 1 ;
V_36 = 1 ;
}
if ( V_36 ) {
F_16 = F_10 ;
F_13 = F_7 ;
} else {
F_16 = F_11 ;
F_13 = F_9 ;
}
if ( V_37 )
F_8 = F_4 ;
else
F_8 = F_1 ;
if ( F_24 ( V_31 , L_4 , & V_3 , 4 ) < 4 )
return - 1 ;
if ( F_25 ( V_31 , V_34 , 2 ) < 2 )
return - 1 ;
if ( V_36 )
V_5 = V_34 [ 0 ] ;
else
V_7 = V_34 [ 0 ] ;
V_10 = V_34 [ 1 ] ;
V_38 = F_26 ( V_31 ) ;
if ( ! V_38 )
return - 1 ;
if ( F_25 ( V_38 , & V_2 , 1 ) < 1 )
return - 1 ;
V_39 = F_27 ( L_5 ) ;
if ( ! V_39 )
return - 1 ;
if ( F_25 ( V_39 , & V_40 , 1 ) < 1 )
return - 1 ;
if ( F_24 ( V_39 , L_6 , V_35 , 8 ) < 8 )
return - 1 ;
V_41 = V_35 [ 0 ] ;
V_42 = V_35 [ 1 ] ;
V_26 = V_41 + V_42 - 2 * sizeof( struct V_28 ) ;
if ( V_37 && V_36 ) {
T_2 * V_43 = ( T_2 * ) V_10 ;
T_2 V_44 ;
V_44 = V_26 - 64 ;
V_44 = F_28 ( V_44 , 64 ) ;
F_13 () ;
F_3 ( V_43 , V_44 ) ;
V_10 = V_40 - V_41 + V_44 ;
}
V_19 = V_40 - V_41 + V_26 ;
V_33 -> V_45 = F_12 ;
V_33 -> putc = F_17 ;
V_33 -> getc = F_21 ;
V_33 -> V_46 = F_20 ;
return 0 ;
}
