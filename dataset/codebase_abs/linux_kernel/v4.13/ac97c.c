static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , unsigned long V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
F_5 () ;
}
static unsigned short F_6 ( struct V_6 * V_7 ,
unsigned short V_8 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
unsigned int V_9 , V_10 ;
unsigned long V_11 ;
V_11 = ~ 0 ;
V_10 = V_12 ;
do {
F_8 ( & V_2 -> V_13 ) ;
V_9 = 5 ;
while ( ( F_1 ( V_2 , V_14 ) & V_15 ) && V_9 -- )
F_9 ( 21 ) ;
if ( ! V_9 ) {
F_10 ( L_1 ) ;
goto V_16;
}
F_3 ( V_2 , V_17 , F_11 ( V_8 ) | V_18 ) ;
V_9 = 0x10000 ;
while ( ( F_1 ( V_2 , V_14 ) & V_15 ) && V_9 -- )
asm volatile ("nop");
V_11 = F_1 ( V_2 , V_17 ) ;
if ( ! V_9 )
F_10 ( L_2 ) ;
V_16:
F_12 ( & V_2 -> V_13 ) ;
} while ( -- V_10 && ! V_9 );
F_10 ( L_3 , V_8 , V_11 , V_10 ) ;
return V_10 ? V_11 & 0xffff : 0xffff ;
}
static void F_13 ( struct V_6 * V_7 , unsigned short V_8 ,
unsigned short V_5 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
unsigned int V_9 , V_10 ;
V_10 = V_12 ;
do {
F_8 ( & V_2 -> V_13 ) ;
for ( V_9 = 5 ; ( F_1 ( V_2 , V_14 ) & V_15 ) && V_9 ; V_9 -- )
F_9 ( 21 ) ;
if ( ! V_9 ) {
F_10 ( L_4 ) ;
goto V_16;
}
F_3 ( V_2 , V_17 , V_19 | F_11 ( V_8 ) | F_14 ( V_5 ) ) ;
for ( V_9 = 10 ; ( F_1 ( V_2 , V_14 ) & V_15 ) && V_9 ; V_9 -- )
F_9 ( 21 ) ;
if ( ! V_9 )
F_10 ( L_5 ) ;
V_16:
F_12 ( & V_2 -> V_13 ) ;
} while ( -- V_10 && ! V_9 );
F_10 ( L_6 , V_8 , V_5 , V_10 ) ;
}
static void F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
F_3 ( V_2 , V_20 , V_2 -> V_21 | V_22 | V_23 ) ;
F_16 ( 20 ) ;
F_3 ( V_2 , V_20 , V_2 -> V_21 | V_22 ) ;
F_3 ( V_2 , V_20 , V_2 -> V_21 ) ;
}
static void F_17 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
int V_24 ;
F_3 ( V_2 , V_20 , V_2 -> V_21 | V_25 ) ;
F_16 ( 500 ) ;
F_3 ( V_2 , V_20 , V_2 -> V_21 ) ;
V_24 = 50 ;
while ( ( ( F_1 ( V_2 , V_14 ) & V_26 ) == 0 ) && -- V_24 )
F_16 ( 20 ) ;
if ( ! V_24 )
F_18 ( V_27 L_7 ) ;
}
static int F_19 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_20 ( V_31 ) ;
F_21 ( V_31 , V_29 , & V_2 -> V_32 [ 0 ] ) ;
return 0 ;
}
static int F_22 ( struct V_30 * V_31 )
{
return V_33 ? 0 : - V_34 ;
}
static int F_23 ( struct V_35 * V_36 )
{
int V_37 ;
struct V_38 * V_39 , * V_40 ;
struct V_1 * V_2 ;
V_2 = F_24 ( & V_36 -> V_41 , sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
F_25 ( & V_2 -> V_13 ) ;
V_39 = F_26 ( V_36 , V_44 , 0 ) ;
if ( ! V_39 )
return - V_34 ;
if ( ! F_27 ( & V_36 -> V_41 , V_39 -> V_45 ,
F_28 ( V_39 ) ,
V_36 -> V_46 ) )
return - V_47 ;
V_2 -> V_4 = F_29 ( & V_36 -> V_41 , V_39 -> V_45 ,
F_28 ( V_39 ) ) ;
if ( ! V_2 -> V_4 )
return - V_47 ;
V_40 = F_26 ( V_36 , V_48 , 0 ) ;
if ( ! V_40 )
return - V_47 ;
V_2 -> V_32 [ V_49 ] = V_40 -> V_45 ;
V_40 = F_26 ( V_36 , V_48 , 1 ) ;
if ( ! V_40 )
return - V_47 ;
V_2 -> V_32 [ V_50 ] = V_40 -> V_45 ;
F_3 ( V_2 , V_51 , V_52 | V_53 ) ;
F_3 ( V_2 , V_51 , V_53 ) ;
V_2 -> V_21 = F_30 ( 3 ) | F_31 ( 3 ) ;
F_3 ( V_2 , V_20 , V_2 -> V_21 ) ;
F_32 ( V_36 , V_2 ) ;
V_37 = F_33 ( & V_54 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_34 ( & V_36 -> V_41 , & V_55 ,
& V_56 , 1 ) ;
if ( V_37 )
return V_37 ;
V_33 = V_2 ;
return 0 ;
}
static int F_35 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_36 ( V_36 ) ;
F_37 ( & V_36 -> V_41 ) ;
F_3 ( V_2 , V_51 , V_52 ) ;
V_33 = NULL ;
return 0 ;
}
static int F_38 ( struct V_57 * V_41 )
{
struct V_1 * V_2 = F_39 ( V_41 ) ;
F_3 ( V_2 , V_51 , V_52 ) ;
return 0 ;
}
static int F_40 ( struct V_57 * V_41 )
{
struct V_1 * V_2 = F_39 ( V_41 ) ;
F_3 ( V_2 , V_51 , V_52 | V_53 ) ;
F_3 ( V_2 , V_51 , V_53 ) ;
F_3 ( V_2 , V_20 , V_2 -> V_21 ) ;
return 0 ;
}
