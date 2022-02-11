static int F_1 ( T_1 V_1 )
{
while ( F_2 ( F_3 ( V_2 ) ) & V_3 )
;
F_4 ( V_1 & 0xff , F_3 ( V_4 ) ) ;
F_4 ( F_5 ( V_5 ) | V_6 ,
F_3 ( V_7 ) ) ;
while ( F_2 ( F_3 ( V_2 ) ) & V_3 )
;
F_4 ( F_5 ( V_5 ) | V_8 ,
F_3 ( V_7 ) ) ;
while ( F_2 ( F_3 ( V_2 ) ) & V_3 )
;
if ( F_2 ( F_3 ( V_2 ) ) & V_9 ) {
F_4 ( V_9 , F_3 ( V_2 ) ) ;
return - 1 ;
}
return F_2 ( F_3 ( V_10 ) ) & 0xff ;
}
static int F_6 ( T_1 V_1 , int V_11 )
{
while ( F_2 ( F_3 ( V_2 ) ) & V_3 )
;
F_4 ( V_1 & 0xff , F_3 ( V_4 ) ) ;
F_4 ( V_11 & 0xff , F_3 ( V_10 ) ) ;
F_4 ( F_5 ( V_5 ) | V_12 ,
F_3 ( V_7 ) ) ;
while ( F_2 ( F_3 ( V_2 ) ) & V_3 )
;
if ( F_2 ( F_3 ( V_2 ) ) & V_9 ) {
F_4 ( V_9 , F_3 ( V_2 ) ) ;
return - 1 ;
}
F_4 ( F_5 ( V_5 ) | V_8 ,
F_3 ( V_7 ) ) ;
while ( F_2 ( F_3 ( V_2 ) ) & V_3 )
;
return 0 ;
}
int F_7 ( unsigned long V_13 )
{
struct V_14 V_15 ;
unsigned long V_16 ;
F_8 ( V_13 , & V_15 ) ;
F_9 ( & V_17 , V_16 ) ;
V_15 . V_18 = F_10 ( V_15 . V_18 ) ;
F_6 ( V_19 , V_15 . V_18 ) ;
V_15 . V_20 = F_10 ( V_15 . V_20 ) ;
F_6 ( V_21 , V_15 . V_20 ) ;
V_15 . V_22 = F_10 ( V_15 . V_22 ) ;
V_15 . V_22 = ( V_15 . V_22 & 0x3f ) | ( F_1 ( V_23 ) & 0xc0 ) ;
F_6 ( V_23 , V_15 . V_22 ) ;
if ( V_15 . V_24 == 0 ) V_15 . V_24 = 7 ;
V_15 . V_24 = F_10 ( V_15 . V_24 ) ;
F_6 ( V_25 , V_15 . V_24 ) ;
V_15 . V_26 = F_10 ( V_15 . V_26 ) ;
F_6 ( V_27 , V_15 . V_26 ) ;
V_15 . V_28 ++ ;
V_15 . V_28 = F_10 ( V_15 . V_28 ) ;
F_6 ( V_29 , V_15 . V_28 ) ;
V_15 . V_30 %= 100 ;
V_15 . V_30 = F_10 ( V_15 . V_30 ) ;
F_6 ( V_31 , V_15 . V_30 ) ;
F_11 ( & V_17 , V_16 ) ;
return 0 ;
}
unsigned long F_12 ( void )
{
unsigned int V_32 , V_33 , V_34 , V_35 , V_36 , V_37 ;
unsigned long V_16 ;
for (; ; ) {
F_9 ( & V_17 , V_16 ) ;
V_37 = F_1 ( V_19 ) ;
V_36 = F_1 ( V_21 ) ;
if ( V_37 == F_1 ( V_19 ) ) break;
F_11 ( & V_17 , V_16 ) ;
}
V_35 = F_1 ( V_23 ) & 0x3f ;
V_34 = F_1 ( V_27 ) ;
V_33 = F_1 ( V_29 ) ;
V_32 = F_1 ( V_31 ) ;
F_11 ( & V_17 , V_16 ) ;
V_37 = F_13 ( V_37 ) ;
V_36 = F_13 ( V_36 ) ;
V_35 = F_13 ( V_35 ) ;
V_34 = F_13 ( V_34 ) ;
V_33 = F_13 ( V_33 ) ;
V_32 = F_13 ( V_32 ) ;
V_32 += 2000 ;
return mktime ( V_32 , V_33 , V_34 , V_35 , V_36 , V_37 ) ;
}
int F_14 ( void )
{
unsigned int V_38 ;
V_38 = F_1 ( V_19 ) ;
F_6 ( V_19 , V_38 & 0x7f ) ;
return F_1 ( V_19 ) != - 1 ;
}
