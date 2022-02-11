static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 >= 0x40 )
return 128 * 32 ;
else
if ( V_4 -> V_6 >= 0x17 )
return 64 * 32 ;
else
if ( V_4 -> V_6 >= 0x10 )
return 32 * 32 ;
return 32 * 16 ;
}
int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_8 = NULL ;
T_1 V_9 , V_10 ;
int V_11 ;
V_4 -> V_12 = true ;
if ( V_4 -> V_13 >= V_14 ) {
T_1 V_15 = F_3 ( ( F_4 ( V_2 , 0x001540 ) & 0x0000ff00 ) >> 8 ) ;
T_1 V_16 ;
if ( V_4 -> V_6 == 0x40 ) V_16 = 0x6aa0 * V_15 ;
else if ( V_4 -> V_6 < 0x43 ) V_16 = 0x4f00 * V_15 ;
else if ( F_5 ( V_2 ) ) V_16 = 0x4980 * V_15 ;
else V_16 = 0x4a40 * V_15 ;
V_16 += 16 * 1024 ;
V_16 *= 32 ;
V_16 += 512 * 1024 ;
V_16 += 512 * 1024 ;
V_4 -> V_17 = F_6 ( V_16 , 4096 ) ;
} else {
V_4 -> V_17 = 512 * 1024 ;
}
V_11 = F_7 ( V_2 , 0x10000 , ~ 0 , 4096 ,
V_18 , & V_8 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_8 ( V_2 , V_8 , & V_4 -> V_8 ) ;
F_9 ( NULL , & V_8 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_7 ( V_2 , 0x11200 , ~ 0 , 512 ,
V_18 , & V_4 -> V_19 ) ;
if ( V_11 )
return V_11 ;
V_10 = F_1 ( V_2 ) ;
switch ( V_4 -> V_13 ) {
case V_14 :
V_9 = 0x20000 ;
break;
default:
V_9 = 0x11400 ;
break;
}
V_11 = F_7 ( V_2 , V_9 , ~ 0 , V_10 ,
V_18 , & V_4 -> V_20 ) ;
if ( V_11 )
return V_11 ;
V_9 += V_10 ;
if ( V_4 -> V_13 >= V_14 ) {
if ( V_9 < 0x40000 )
V_9 = 0x40000 ;
}
V_11 = F_10 ( & V_4 -> V_21 , V_9 ,
V_4 -> V_17 - V_9 ) ;
if ( V_11 ) {
F_11 ( V_2 , L_1 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
void
F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_13 ( NULL , & V_4 -> V_8 , NULL ) ;
F_9 ( NULL , & V_4 -> V_19 ) ;
F_9 ( NULL , & V_4 -> V_20 ) ;
if ( F_14 ( & V_4 -> V_21 ) )
F_15 ( & V_4 -> V_21 ) ;
}
int
F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
void
F_17 ( struct V_1 * V_2 )
{
}
int
F_18 ( struct V_7 * V_22 , struct V_23 * V_24 ,
T_1 V_25 , T_1 V_26 )
{
struct V_3 * V_4 = V_22 -> V_2 -> V_5 ;
struct V_27 * V_28 = NULL ;
do {
if ( F_19 ( & V_4 -> V_21 ) )
return - V_29 ;
F_20 ( & V_4 -> V_30 ) ;
V_28 = F_21 ( & V_4 -> V_21 , V_25 , V_26 , 0 ) ;
if ( V_28 == NULL ) {
F_22 ( & V_4 -> V_30 ) ;
return - V_29 ;
}
V_28 = F_23 ( V_28 , V_25 , V_26 ) ;
F_22 ( & V_4 -> V_30 ) ;
} while ( V_28 == NULL );
V_22 -> V_31 = V_28 ;
V_22 -> V_32 = V_28 -> V_33 ;
return 0 ;
}
void
F_24 ( struct V_7 * V_22 )
{
struct V_3 * V_4 = V_22 -> V_2 -> V_5 ;
F_20 ( & V_4 -> V_30 ) ;
F_25 ( V_22 -> V_31 ) ;
V_22 -> V_31 = NULL ;
F_22 ( & V_4 -> V_30 ) ;
}
int
F_26 ( struct V_7 * V_22 )
{
V_22 -> V_34 = V_22 -> V_32 ;
return 0 ;
}
void
F_27 ( struct V_7 * V_22 )
{
}
void
F_28 ( struct V_1 * V_2 )
{
}
