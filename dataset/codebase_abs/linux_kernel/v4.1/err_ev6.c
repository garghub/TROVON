static int
F_1 ( T_1 V_1 , int V_2 )
{
int V_3 = V_4 ;
#define F_2 (1UL << 29)
#define F_3 (EV6__I_STAT__PAR)
if ( ! ( V_1 & F_3 ) )
return V_5 ;
if ( ! V_2 )
return V_3 ;
if ( V_1 & F_2 )
F_4 ( L_1 , V_6 ) ;
return V_3 ;
}
static int
F_5 ( T_1 V_7 , T_1 V_8 , T_1 V_9 , int V_2 )
{
int V_3 = V_4 ;
#define F_6 (1UL << 10)
#define F_7 (EV6__MM_STAT__DC_TAG_PERR)
#define F_8 (1UL << 0)
#define F_9 (1UL << 1)
#define F_10 (1UL << 2)
#define F_11 (1UL << 3)
#define F_12 (1UL << 4)
#define F_13 (EV6__D_STAT__TPERR_P0 | \
EV6__D_STAT__TPERR_P1 | \
EV6__D_STAT__ECC_ERR_ST | \
EV6__D_STAT__ECC_ERR_LD | \
EV6__D_STAT__SEO)
if ( ! ( V_8 & F_13 ) &&
! ( V_7 & F_7 ) )
return V_5 ;
if ( ! V_2 )
return V_3 ;
if ( V_7 & F_6 )
F_4 ( L_2 ,
V_6 ) ;
if ( V_8 & F_8 )
F_4 ( L_3 ,
V_6 ) ;
if ( V_8 & F_9 )
F_4 ( L_4 ,
V_6 ) ;
if ( V_8 & F_10 )
F_4 ( L_5 ,
V_6 ) ;
if ( V_8 & F_11 )
F_4 ( L_6 ,
V_6 ,
V_9 ? L_7 : L_8 ) ;
if ( V_8 & F_12 )
F_4 ( L_9 , V_6 ) ;
return V_3 ;
}
static int
F_14 ( T_1 V_10 , T_1 V_11 , T_1 V_12 ,
T_1 V_9 , T_1 V_13 , int V_2 )
{
static const char * const V_14 [] = {
L_10 , L_10 , L_10 ,
L_11 , L_12 , L_13 ,
L_14 , L_14
} ;
static const char * const V_15 [] = { L_15 , L_16 } ;
static const char * const V_16 [] = { L_17 , L_18 } ;
int V_3 = V_4 ;
int V_17 = - 1 , V_18 = - 1 , V_19 = - 1 ;
#define F_15 (0x01)
#define F_16 (0x02)
#define F_17 (0x03)
#define F_18 (0x04)
#define F_19 (0x05)
#define F_20 (0x06)
#define F_21 (0x07)
#define F_22 (0x0B)
#define F_23 (0x0C)
#define F_24 (0x13)
#define F_25 (0x14)
#define F_26 (0x1B)
#define F_27 (0x1C)
#define F_28 (0x03)
#define F_29 (0x04)
#define F_30 (0)
#define F_31 (0x07)
#define F_32 (3)
#define F_33 (0x01)
#define F_34 (4)
#define F_35 (0x01)
#define F_36 (0x1F)
#define F_37 (1 << 0)
#define F_38 (1 << 1)
#define F_39 (1 << 2)
#define F_40 (1 << 3)
if ( ! ( V_9 & F_36 ) )
return V_5 ;
if ( ! V_2 )
return V_3 ;
V_17 = F_41 ( V_9 , V_20 ) ;
V_18 = F_41 ( V_9 , V_21 ) ;
V_19 = F_41 ( V_9 , V_22 ) ;
if ( V_9 & F_15 ) {
F_4 ( L_19 , V_6 ) ;
V_17 = - 1 ;
}
if ( V_9 & F_16 ) {
F_4 ( L_20 , V_6 ) ;
V_17 = - 1 ;
}
if ( V_9 == F_20 ||
V_9 == F_21 ) {
F_4 ( L_21 ,
V_6 ) ;
V_17 = - 1 ;
}
if ( V_17 != - 1 )
F_4 ( L_22 ,
V_6 ,
V_15 [ V_18 ] , V_16 [ V_19 ] , V_14 [ V_17 ] ) ;
F_4 ( L_23
L_24 ,
V_6 ,
V_10 ,
V_12 , V_11 ) ;
if ( V_17 == F_28 ||
V_17 == F_29 )
F_4 ( L_25 ,
V_6 ,
( V_13 & F_37 ) ? L_26 : L_7 ,
( V_13 & F_38 ) ? L_27 : L_7 ,
( V_13 & F_39 ) ? L_28 : L_7 ,
( V_13 & F_40 ) ? L_29 : L_7 ) ;
return V_3 ;
}
void
F_42 ( void )
{
}
int
F_43 ( struct V_23 * V_24 , int V_2 )
{
struct V_25 * V_26 =
(struct V_25 * ) V_24 ;
int V_3 = V_5 ;
V_3 |= F_1 ( V_26 -> V_27 , V_2 ) ;
V_3 |= F_5 ( V_26 -> V_28 , V_26 -> V_29 ,
V_26 -> V_30 , V_2 ) ;
V_3 |= F_14 ( V_26 -> V_31 , V_26 -> V_32 ,
V_26 -> V_33 , V_26 -> V_30 ,
V_26 -> V_34 , V_2 ) ;
if ( ! V_2 )
return V_3 ;
if ( V_3 != V_35 ) {
char * V_36 = V_6 ;
F_4 ( L_30
L_31
L_32
L_33 ,
V_6 ,
V_26 -> V_37 , V_26 -> V_38 , V_26 -> V_39 ,
V_26 -> V_40 , V_26 -> V_41 , V_26 -> V_42 ) ;
if ( V_3 == V_5 ) {
F_4 ( L_34 ,
V_6 ) ;
} else {
V_6 = V_43 ;
}
F_44 ( V_24 ) ;
V_6 = V_36 ;
}
return V_3 ;
}
void
F_45 ( unsigned long V_44 , unsigned long V_45 )
{
struct V_23 * V_24 = (struct V_23 * ) V_45 ;
F_46 () ;
F_47 () ;
if ( F_43 ( V_24 , 0 ) !=
V_35 ) {
char * V_36 = V_6 ;
V_6 = V_46 ;
F_4 ( L_35 ,
V_6 ,
( V_44 == V_47 ) ? L_36 : L_37 ,
( unsigned int ) V_44 , ( int ) F_48 () ) ;
F_43 ( V_24 , 1 ) ;
F_49 ( F_50 () , NULL ) ;
V_6 = V_36 ;
}
F_51 ( 0x7 ) ;
F_46 () ;
}
