void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 . V_5 , V_3 ) ;
F_3 ( V_2 ) ;
if ( V_2 -> V_6 != V_7 )
V_2 -> V_6 ++ ;
F_4 ( & V_2 -> V_4 , V_8 , 1 ) ;
F_5 ( & V_2 -> V_4 . V_5 , V_3 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( & V_2 -> V_4 . V_5 , V_3 ) ;
V_2 -> V_6 = V_7 ;
F_4 ( & V_2 -> V_4 , V_8 , 0 ) ;
F_5 ( & V_2 -> V_4 . V_5 , V_3 ) ;
}
static inline long T_1
F_7 ( struct V_1 * V_2 ,
long (* F_8)( long ) , long V_9 , int V_10 )
{
if ( ! V_2 -> V_6 ) {
F_9 ( V_4 , V_11 ) ;
F_10 ( & V_2 -> V_4 , & V_4 ) ;
do {
if ( F_11 ( V_10 , V_11 ) ) {
V_9 = - V_12 ;
break;
}
F_12 ( V_10 ) ;
F_13 ( & V_2 -> V_4 . V_5 ) ;
V_9 = F_8 ( V_9 ) ;
F_14 ( & V_2 -> V_4 . V_5 ) ;
} while ( ! V_2 -> V_6 && V_9 );
F_15 ( & V_2 -> V_4 , & V_4 ) ;
if ( ! V_2 -> V_6 )
return V_9 ;
}
if ( V_2 -> V_6 != V_7 )
V_2 -> V_6 -- ;
return V_9 ? : 1 ;
}
static inline long T_1
F_16 ( struct V_1 * V_2 ,
long (* F_8)( long ) , long V_9 , int V_10 )
{
F_17 () ;
F_18 ( V_2 ) ;
F_14 ( & V_2 -> V_4 . V_5 ) ;
V_9 = F_7 ( V_2 , F_8 , V_9 , V_10 ) ;
F_13 ( & V_2 -> V_4 . V_5 ) ;
F_19 ( V_2 ) ;
return V_9 ;
}
static long T_1
F_20 ( struct V_1 * V_2 , long V_9 , int V_10 )
{
return F_16 ( V_2 , V_13 , V_9 , V_10 ) ;
}
static long T_1
F_21 ( struct V_1 * V_2 , long V_9 , int V_10 )
{
return F_16 ( V_2 , V_14 , V_9 , V_10 ) ;
}
void T_1 F_22 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_15 , V_16 ) ;
}
unsigned long T_1
F_23 ( struct V_1 * V_2 , unsigned long V_9 )
{
return F_20 ( V_2 , V_9 , V_16 ) ;
}
void T_1 F_24 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_15 , V_16 ) ;
}
unsigned long T_1
F_25 ( struct V_1 * V_2 , unsigned long V_9 )
{
return F_21 ( V_2 , V_9 , V_16 ) ;
}
int T_1 F_26 ( struct V_1 * V_2 )
{
long V_17 = F_20 ( V_2 , V_15 , V_18 ) ;
if ( V_17 == - V_12 )
return V_17 ;
return 0 ;
}
long T_1
F_27 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
return F_20 ( V_2 , V_9 , V_18 ) ;
}
int T_1 F_28 ( struct V_1 * V_2 )
{
long V_17 = F_20 ( V_2 , V_15 , V_19 ) ;
if ( V_17 == - V_12 )
return V_17 ;
return 0 ;
}
long T_1
F_29 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
return F_20 ( V_2 , V_9 , V_19 ) ;
}
bool F_30 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_20 = 1 ;
if ( ! F_31 ( V_2 -> V_6 ) )
return 0 ;
F_2 ( & V_2 -> V_4 . V_5 , V_3 ) ;
if ( ! V_2 -> V_6 )
V_20 = 0 ;
else if ( V_2 -> V_6 != V_7 )
V_2 -> V_6 -- ;
F_5 ( & V_2 -> V_4 . V_5 , V_3 ) ;
return V_20 ;
}
bool F_32 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( ! F_31 ( V_2 -> V_6 ) )
return false ;
F_2 ( & V_2 -> V_4 . V_5 , V_3 ) ;
F_5 ( & V_2 -> V_4 . V_5 , V_3 ) ;
return true ;
}
